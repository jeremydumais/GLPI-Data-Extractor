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
};

#endif // FORMPREFERENCES_H
