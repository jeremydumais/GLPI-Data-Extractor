#include "formmain.h"
#include <QtWidgets/QApplication>
#include <qfile.h>

int main(int argc, char *argv[])
{
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
