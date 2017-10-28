#ifndef FORMABOUT_H
#define FORMABOUT_H

#include <QDialog>
#include "ui_formabout.h"

class FormAbout : public QDialog, public Ui::FormAbout
{
	Q_OBJECT

public:
	FormAbout(QWidget *parent = 0);
	~FormAbout();

private:
	Ui::FormAbout ui;
};

#endif // FORMABOUT_H
