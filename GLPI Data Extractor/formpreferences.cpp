#include "formpreferences.h"

FormPreferences::FormPreferences(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

FormPreferences::~FormPreferences()
{

}
