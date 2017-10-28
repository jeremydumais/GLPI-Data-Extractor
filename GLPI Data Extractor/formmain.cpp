#include "formmain.h"
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
	connect(ui.pushButtonExecute, SIGNAL(clicked()), this, SLOT(pushButtonExecute_Click()));
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
