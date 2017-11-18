#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QtWidgets/QMainWindow>
#include <list>
#include "ui_formmain.h"
#include "ExtractionJob.h"

class FormMain : public QMainWindow
{
	Q_OBJECT

public:
	FormMain(QWidget *parent = 0);
	~FormMain();
	void refreshJobList();

private:
	Ui::FormMainClass ui;
	std::list<ExtractionJob> m_jobs;
private slots:
	void pushButtonExecute_Click();
	void pushButtonPreferences_Click();
	void pushButtonAbout_Click();
	void pushButtonAddJob_Click();
	void pushButtonUpdateJob_Click();
	void pushButtonDeleteJob_Click();
	void tableItemDoubleClicked(int row, int column);
};

#endif // FORMMAIN_H
