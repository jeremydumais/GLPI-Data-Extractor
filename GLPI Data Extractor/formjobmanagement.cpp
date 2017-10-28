#include "formjobmanagement.h"
#include <string>
#include <qmessagebox.h>

using namespace std;

FormJobManagement::FormJobManagement(QWidget *parent, FormManagementType p_action)
	: QDialog(parent), formAction(p_action), result("temporaryJob1")
{
	ui.setupUi(this);
	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(pushButtonOK_Click()));

	string title = "";
	if (formAction == FormManagementType::Add)
		title = "Ajout d'un travail";
	else
		title = "Modification d'un travail";

	setWindowTitle(title.c_str());
	ui.labelTitle->setText(title.c_str());
}

FormJobManagement::~FormJobManagement()
{

}

void FormJobManagement::pushButtonOK_Click()
{
	list<unsigned int> ticketList;
	if (ui.lineEditName->text().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("Le nom du travail ne peut être vide!"));
	else if (ui.plainTextEditTicketIds->toPlainText().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("La liste des numéros de billets ne peut être vide!"));
	else if(!extractTicketList(ui.plainTextEditTicketIds->toPlainText().toStdString(), ticketList))
		QMessageBox::critical(this, "Erreur", QLatin1String("La liste des numéros de billets contient un ou des éléments invalides!"));
	else
	{
		try
		{
			result.setName(ui.lineEditName->text().toStdString());
			accept();
		}
		catch (invalid_argument e)
		{
			QMessageBox::critical(this, "Erreur", QLatin1String("Une erreur s'est produite!"));
		}
	}
}

const ExtractionJob &FormJobManagement::getResult() const
{
	return result;
}

bool FormJobManagement::extractTicketList(const string &p_tickets, list<unsigned int> &ticketList)
{
	for (char c : p_tickets)
	{

	}
	return false;
}
