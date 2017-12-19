#include "formmain.h"
#include "formabout.h"
#include "formjobmanagement.h"
#include "formpreferences.h"
#include "wkhtmltox\pdf.h"
#define HAVE_STRUCT_TIMESPEC
#include "pthread.h"
#include <qstandarditemmodel.h>
#include <list>
#include <qmessagebox.h>
#include <qsettings.h>
#include "formextract.h"

using namespace std;

FormMain::FormMain(QWidget *parent)
	: QMainWindow(parent), m_jobs(list<ExtractionJob>()), m_formExtract(nullptr), m_timerExtract(this)
{
	ui.setupUi(this);
	ui.tableWidgetJobs->setColumnWidth(0, 200);
	ui.tableWidgetJobs->setColumnWidth(1, 150);
	ui.tableWidgetTicketsInJob->setColumnWidth(0, 220);
	ui.progressBarExecution->setVisible(false);
	connect(ui.pushButton_AddJob, SIGNAL(clicked()), this, SLOT(pushButtonAddJob_Click()));
	connect(ui.pushButton_UpdateJob, SIGNAL(clicked()), this, SLOT(pushButtonUpdateJob_Click()));
	connect(ui.pushButton_DeleteJob, SIGNAL(clicked()), this, SLOT(pushButtonDeleteJob_Click()));
	connect(ui.tableWidgetJobs, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(tableItemDoubleClicked(int, int)));
	connect(ui.tableWidgetJobs, SIGNAL(itemPressed(QTableWidgetItem *)), this, SLOT(itemPressed(QTableWidgetItem *)));
	connect(ui.pushButtonExecute, SIGNAL(clicked()), this, SLOT(pushButtonExecute_Click()));
	connect(ui.action_Preferences, SIGNAL(triggered()), this, SLOT(pushButtonPreferences_Click()));
	connect(ui.action_About, SIGNAL(triggered()), this, SLOT(pushButtonAbout_Click()));
	connect(&m_timerExtract, SIGNAL(timeout()), this, SLOT(timerUpdate()));

	m_jobs.push_back(ExtractionJob("test"));
	m_jobs.front().addTicketId(34004);
	m_jobs.front().addTicketId(34005);
	refreshJobList();
}

FormMain::~FormMain()
{
	if (m_formExtract != nullptr)
		delete m_formExtract;
}

void FormMain::pushButtonExecute_Click()
{
	QSettings settings;
	QString glpiUrl = settings.value("GLPIUrl", "").toString();
	QString outputFolder = settings.value("OutputFolder", "").toString().trimmed();
	//Sanitize the output folder
	if (outputFolder[outputFolder.size() - 1] != '\\')
		outputFolder += '\\';

	if (m_jobs.size() == 0)
		QMessageBox::warning(this, "Erreur", QLatin1String("Il n'y a aucun travail à exécuter!"));
	//Check if the output folder and the GLPI url has been correctly sets
	else if (glpiUrl.isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("L'adresse web du système GLPI n'est pas configuré. Voir dans les préférences..."));
	else if (outputFolder.isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("Le dossier d'enregistrement des fichiers n'est pas configuré. Voir dans les préférences..."));
	else
	{
		if (m_formExtract == nullptr)
			m_formExtract = new FormExtract();
		if (settings.value("DisplayDebugWindow").toBool())
			m_formExtract->show();
		ui.labelExtractInfo->setText(QLatin1String("Préparation du navigateur..."));
		ui.labelExtractInfo->show();
		ui.progressBarExecution->setValue(0);
		ui.progressBarExecution->show();
		m_timerExtract.start(1000);
	}
}

void FormMain::pushButtonPreferences_Click()
{
	FormPreferences formPreferences(this);
	if (formPreferences.exec() == QDialog::Accepted)
	{
	}
}

void FormMain::pushButtonAbout_Click()
{
	FormAbout formAbout(this);
	formAbout.exec();
}

void FormMain::pushButtonAddJob_Click()
{
	FormJobManagement formJobManagement(this);
	formJobManagement.PrepareFormData(m_jobs);
	if (formJobManagement.exec() == QDialog::Accepted)
	{
		m_jobs.push_back(formJobManagement.getResult());
		refreshJobList();
	}
}

void FormMain::pushButtonUpdateJob_Click()
{
	if (ui.tableWidgetJobs->selectedItems().size() > 0)
	{
		tableItemDoubleClicked(ui.tableWidgetJobs->selectedItems().first()->row(), 0);
	}
}

void FormMain::refreshJobList()
{
	unsigned int row = 0;
	ui.tableWidgetJobs->setRowCount(m_jobs.size());
	for (auto item : m_jobs)
	{
		ui.tableWidgetJobs->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(item.getName())));
		ui.tableWidgetJobs->setItem(row, 1, new QTableWidgetItem(QString::number(item.getTicketsCount())));
		row++;
	}
}

void FormMain::tableItemDoubleClicked(int row, int column)
{
	QTableWidgetItem *item = ui.tableWidgetJobs->item(row, 0);
	string jobNameToUpdate = item->text().toStdString();
	FormJobManagement formJobManagement(this, FormManagementType::Update);
	formJobManagement.PrepareFormData(m_jobs, jobNameToUpdate);
	if (formJobManagement.exec() == QDialog::Accepted)
	{
		//Find the element to update in the list
		auto it = find_if(m_jobs.begin(), m_jobs.end(), [&jobNameToUpdate](const ExtractionJob &job) { return job.getName() == jobNameToUpdate; });
		it->setName(formJobManagement.getResult().getName());
		it->setTicketIds(formJobManagement.getResult().getTicketIds());
		refreshJobList();
	}
}

void FormMain::itemPressed(QTableWidgetItem *item)
{
	ui.tableWidgetTicketsInJob->setRowCount(0);
	QTableWidgetItem *cellJobName = ui.tableWidgetJobs->item(item->row(), 0);
	string jobNameToDisplay = cellJobName->text().toStdString();
	auto it = find_if(m_jobs.begin(), m_jobs.end(), [&jobNameToDisplay](const ExtractionJob &job) { return job.getName() == jobNameToDisplay; });
	if (it != m_jobs.end())
	{
		unsigned int row = 0;
		ui.tableWidgetTicketsInJob->setRowCount(it->getTicketsCount());
		for (auto ticketId : it->getTicketIds())
		{
			ui.tableWidgetTicketsInJob->setItem(row, 0, new QTableWidgetItem(QString::number(ticketId)));
			row++;
		}
	}
}

void FormMain::pushButtonDeleteJob_Click()
{
	if (ui.tableWidgetJobs->selectedItems().size() > 0)
	{
		if (QMessageBox::question(this, "Confirmation", QLatin1String("Êtes-vous certain de vouloir supprimer le travail sélectionné?"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::No) == QMessageBox::Yes)
		{
			QTableWidgetItem *item = ui.tableWidgetJobs->item(ui.tableWidgetJobs->selectedItems().first()->row(), 0);
			string jobNameToDelete = item->text().toStdString();
			auto it = find_if(m_jobs.begin(), m_jobs.end(), [&jobNameToDelete](const ExtractionJob &job) { return job.getName() == jobNameToDelete; });
			m_jobs.erase(it);
			refreshJobList();
		}
	}
}

void FormMain::timerUpdate()
{
	ui.labelExtractInfo->setText(stateToString(m_formExtract->getState()));
	if (m_formExtract->getState() == ExtractState::LoggedIn)
	{
		m_formExtract->ExtractJob(m_jobs.front());
	}
	else if (m_formExtract->getState() == ExtractState::ExtractionJobComplete)
	{
		m_timerExtract.stop();
		ui.labelExtractInfo->setText(QLatin1String("Extraction terminé!"));
		ui.progressBarExecution->setValue(100);
		//QMessageBox::information(this, "Information", QLatin1String("Extraction terminé!"));
		delete m_formExtract;
		m_formExtract = nullptr;
	}
}

QString FormMain::stateToString(const ExtractState &p_state) const
{
	if (p_state == ExtractState::Undefined)
		return "";
	else if (p_state == ExtractState::Authentication)
		return "Authentification";
	else if (p_state == ExtractState::BadAuthInfo)
		return "Mauvaise information de connexion";
	else if (p_state == ExtractState::LoggedIn)
		return QLatin1String("Authentifié");
	else
		return "";
}