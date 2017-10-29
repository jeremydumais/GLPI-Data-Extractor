#include "formmain.h"
#include "formabout.h"
#include "formjobmanagement.h"
#include "formpreferences.h"
#include "wkhtmltox\pdf.h"
#define HAVE_STRUCT_TIMESPEC
#include "pthread.h"
#include <qstandarditemmodel.h>

FormMain::FormMain(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	/*ui.menuBar->setStyleSheet("QMenuBar::item:selected { background: #a8a8a8; }");
	ui.tableWidgetJobs->verticalHeader()->setStyleSheet("::section { background-color: rgb(66, 66, 66); }");
	ui.tableWidgetJobs->horizontalHeader()->setStyleSheet("::section { background-color: rgb(66, 66, 66); }");*/
	//ui.tableWidgetJobs->setRowCount(5);
	ui.tableWidgetJobs->setColumnWidth(0, 200);
	ui.tableWidgetJobs->setColumnWidth(1, 150);
	ui.progressBarExecution->setVisible(false);
	connect(ui.pushButton_AddJob, SIGNAL(clicked()), this, SLOT(pushButtonAddJob_Click()));
	connect(ui.pushButton_UpdateJob, SIGNAL(clicked()), this, SLOT(pushButtonUpdateJob_Click()));
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
	if (formJobManagement.exec() == QDialog::Accepted)
	{
		m_jobs.push_back(formJobManagement.getResult());
		refreshJobList();
	}
}

void FormMain::pushButtonUpdateJob_Click()
{
	FormJobManagement formJobManagement(this, FormManagementType::Update);
	if (formJobManagement.exec() == QDialog::Accepted)
	{
		refreshJobList();
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
	QTableWidgetItem *item = new QTableWidgetItem;
	item = ui.tableWidgetJobs->item(row, column);
	FormJobManagement formJobManagement(this, FormManagementType::Update);
	if (formJobManagement.exec() == QDialog::Accepted)
	{
		refreshJobList();
	}
}