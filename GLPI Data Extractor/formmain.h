#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QtWidgets/QMainWindow>
#include <qtimer.h>
#include <list>
#include "ui_formmain.h"
#include "ExtractionJob.h"
#include "formextract.h"
#include "extractState.h"

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
	FormExtract *m_formExtract;
	QTimer m_timerExtract;
	QString stateToString(const ExtractState &p_state) const;
private slots:
	void pushButtonExecute_Click();
	void pushButtonPreferences_Click();
	void pushButtonAbout_Click();
	void pushButtonAddJob_Click();
	void pushButtonUpdateJob_Click();
	void pushButtonDeleteJob_Click();
	void tableItemDoubleClicked(int row, int column);
	void itemPressed(QTableWidgetItem *item);
	void timerUpdate();
};

#endif // FORMMAIN_H
