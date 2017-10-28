#include "formmain.h"
#include "formabout.h"
#include "formjobmanagement.h"
#include "wkhtmltox\pdf.h"
#define HAVE_STRUCT_TIMESPEC
#include "pthread.h"



FormMain::FormMain(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnWidth(0, 200);
	ui.tableWidget->setColumnWidth(1, 150);
	ui.progressBarExecution->setVisible(false);
	connect(ui.pushButton_AddJob, SIGNAL(clicked()), this, SLOT(pushButtonAddJob_Click()));
	connect(ui.pushButton_UpdateJob, SIGNAL(clicked()), this, SLOT(pushButtonUpdateJob_Click()));
	connect(ui.pushButtonExecute, SIGNAL(clicked()), this, SLOT(pushButtonExecute_Click()));
	connect(ui.action_About, SIGNAL(triggered()), this, SLOT(pushButtonAbout_Click()));
}

FormMain::~FormMain()
{

}

void FormMain::pushButtonExecute_Click()
{
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
		setWindowTitle(QString::number(formJobManagement.getResult().getTicketsCount()));
	}
}

void FormMain::pushButtonUpdateJob_Click()
{
	FormJobManagement formJobManagement(this, FormManagementType::Update);
	if (formJobManagement.exec() == QDialog::Accepted)
	{

	}
}