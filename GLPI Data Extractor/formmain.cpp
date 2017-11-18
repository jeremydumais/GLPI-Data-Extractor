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

using namespace std;

FormMain::FormMain(QWidget *parent)
	: QMainWindow(parent), m_jobs(list<ExtractionJob>())
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
	connect(ui.pushButtonExecute, SIGNAL(clicked()), this, SLOT(pushButtonExecute_Click()));
	connect(ui.action_Preferences, SIGNAL(triggered()), this, SLOT(pushButtonPreferences_Click()));
	connect(ui.action_About, SIGNAL(triggered()), this, SLOT(pushButtonAbout_Click()));
}

FormMain::~FormMain()
{

}

void FormMain::pushButtonExecute_Click()
{
	//ui.pushButtonExecute->setEnabled(false);
	wkhtmltopdf_init(0);
	wkhtmltopdf_global_settings *global = wkhtmltopdf_create_global_settings();
	wkhtmltopdf_set_global_setting(global, "out", "test.pdf");
	wkhtmltopdf_converter *converter = wkhtmltopdf_create_converter(global);
	wkhtmltopdf_object_settings* object = wkhtmltopdf_create_object_settings();
	wkhtmltopdf_set_object_setting(object, "page", "https://github.com/wkhtmltopdf/wkhtmltopdf");
	wkhtmltopdf_add_object(converter, object, NULL);
	wkhtmltopdf_convert(converter);
	wkhtmltopdf_destroy_converter(converter);
	wkhtmltopdf_deinit();
	//ui.pushButtonExecute->setEnabled(true);
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

void FormMain::pushButtonDeleteJob_Click()
{
	if (ui.tableWidgetJobs->selectedItems().size() > 0)
	{
		if (QMessageBox::question(this, "Confirmation", QLatin1String("�tes-vous certain de vouloir supprimer le travail s�lectionn�?"),
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
