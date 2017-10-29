#include "formjobmanagement.h"
#include <string>
#include <qmessagebox.h>
#include "CSVParser.h"

using namespace std;

FormJobManagement::FormJobManagement(QWidget *parent, FormManagementType p_action)
	: QDialog(parent), m_formAction(p_action), m_result("temporaryJob1"), m_actualList(list<ExtractionJob>()), m_jobNameToUpdate("")
{
	ui.setupUi(this);
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(pushButtonOK_Click()));

	string title = "";
	if (m_formAction == FormManagementType::Add)
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
	//string t = ui.plainTextEditTicketIds->toPlainText().toStdString();
	CSVParser csv;
	if (ui.lineEditName->text().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("Le nom du travail ne peut être vide!"));
	else if (ui.plainTextEditTicketIds->toPlainText().isEmpty())
		QMessageBox::critical(this, "Erreur", QLatin1String("La liste des numéros de billets ne peut être vide!"));
	else if(!csv.ParseUIntList(ui.plainTextEditTicketIds->toPlainText().toStdString(), ticketList))
		QMessageBox::critical(this, "Erreur", QLatin1String("La liste des numéros de billets contient un ou des éléments invalides!"));
	else
	{
		try
		{
			m_result.setName(ui.lineEditName->text().toStdString());
			for (unsigned int i : ticketList)
				m_result.addTicketId(i);
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
	return m_result;
}

void FormJobManagement::PrepareUpdateData(list<ExtractionJob> &p_actualList, const string &p_jobNameToUpdate)
{
	m_actualList = p_actualList;
	m_jobNameToUpdate = p_jobNameToUpdate;
	ui.lineEditName->setText(QString::fromStdString(m_jobNameToUpdate));
	//Find the element to update in the list
	list<ExtractionJob>::iterator it = find_if(m_actualList.begin(), m_actualList.end(), [&p_jobNameToUpdate](const ExtractionJob &job) { return job.getName() == p_jobNameToUpdate; });
	QString strResult = "";
	for (auto elem : it->getTicketIds())
	{
		if (!strResult.isEmpty())
			strResult += ", ";
		strResult += QString::number(elem);
	}
	ui.plainTextEditTicketIds->setPlainText(strResult);
}
