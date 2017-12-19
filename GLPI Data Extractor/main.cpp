#include "formmain.h"
#include "formpreferences.h"
#include <QtWidgets/QApplication>
#include <qfile.h>

int main(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("JedSharp Software");
	QCoreApplication::setOrganizationDomain("jedsharpsoftware.com");
	QCoreApplication::setApplicationName("GLPI Data Extractor");
	QApplication a(argc, argv);
	
	FormMain w;
	w.show(); 
	QFile file("qdarkstyle/style.qss");
	if (!file.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		file.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&file);
		qApp->setStyleSheet(ts.readAll());
	}
	return a.exec();
}
