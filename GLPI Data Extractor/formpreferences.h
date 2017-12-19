#ifndef FORMPREFERENCES_H
#define FORMPREFERENCES_H

#include <QDialog>
#include "ui_formpreferences.h"

class FormPreferences : public QDialog
{
	Q_OBJECT

public:
	FormPreferences(QWidget *parent = 0);
	~FormPreferences();
private:
	Ui::FormPreferences ui;

private slots:
	void showEvent(QShowEvent* event);
	void pushButtonOK_Click();
	void pushButtonEtcFolder_Click();
	void loadfinished(bool ok);
};

#endif // FORMPREFERENCES_H
