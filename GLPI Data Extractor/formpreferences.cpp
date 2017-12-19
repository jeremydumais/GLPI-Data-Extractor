#include "formpreferences.h"
#include <qsettings.h>
#include <qmessagebox.h>
#include <qfiledialog.h>

FormPreferences::FormPreferences(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(pushButtonOK_Click()));
	connect(ui.pushButtonEtcFolder, SIGNAL(clicked()), this, SLOT(pushButtonEtcFolder_Click()));
}

FormPreferences::~FormPreferences()
{
}

void FormPreferences::showEvent(QShowEvent* event) 
{
	QWidget::showEvent(event);
	QSettings settings;
	ui.lineEditGLPIAddress->setText(settings.value("GLPIUrl", "").toString());
	ui.lineEditOutputFolder->setText(settings.value("OutputFolder", "").toString());
	ui.checkBoxDebugWindow->setChecked(settings.value("DisplayDebugWindow", false).toBool());
}

void FormPreferences::pushButtonOK_Click()
{
	QUrl url(ui.lineEditGLPIAddress->text());
	if (ui.lineEditGLPIAddress->text().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("L'adresse web du système GLPI ne peut être vide!"));
	else if (!url.isValid())
		QMessageBox::critical(this, "Erreur", QLatin1String("L'adresse web du système GLPI est invalide!")); 
	else if (ui.lineEditOutputFolder->text().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("Le dossier d'enregistrement des fichiers ne peut être vide!"));
	else
	{
		QSettings settings;
		settings.setValue("GLPIUrl", ui.lineEditGLPIAddress->text());
		settings.setValue("OutputFolder", ui.lineEditOutputFolder->text());
		settings.setValue("DisplayDebugWindow", ui.checkBoxDebugWindow->isChecked());
		accept();
	}
}

void FormPreferences::loadfinished(bool ok)
{
}

void FormPreferences::pushButtonEtcFolder_Click()
{
	QFileDialog dialog;
	dialog.setFileMode(QFileDialog::Directory);
	dialog.setOption(QFileDialog::ShowDirsOnly);
	if (dialog.exec() == QFileDialog::Accepted)
		ui.lineEditOutputFolder->setText(dialog.selectedFiles()[0]);
}


