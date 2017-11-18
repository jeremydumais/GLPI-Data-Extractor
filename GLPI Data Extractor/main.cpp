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
	QFile file("default.qss");
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet(file.readAll());
		a.setStyleSheet(styleSheet);
	}
	return a.exec();
}
