#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_formmain.h"

class FormMain : public QMainWindow
{
	Q_OBJECT

public:
	FormMain(QWidget *parent = 0);
	~FormMain();

private:
	Ui::FormMainClass ui;
private slots:
	void pushButtonExecute_Click();
	void pushButtonAbout_Click();
	void pushButtonAddJob_Click();
	void pushButtonUpdateJob_Click();
};

#endif // FORMMAIN_H
