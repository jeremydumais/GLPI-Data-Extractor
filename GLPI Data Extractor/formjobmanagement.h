#ifndef FORMJOBMANAGEMENT_H
#define FORMJOBMANAGEMENT_H

#include <QDialog>
#include <list>
#include "ui_formjobmanagement.h"
#include "formmanagementtype.h"
#include "ExtractionJob.h"

class FormJobManagement : public QDialog
{
	Q_OBJECT

public:
	FormJobManagement(QWidget *parent = 0, FormManagementType p_action = FormManagementType::Add);
	~FormJobManagement();

	FormManagementType formAction;
	const ExtractionJob &getResult() const;

	bool extractTicketList(const std::string &p_tickets, std::list<unsigned int> &ticketList);

private:
	Ui::FormJobManagement ui;
	ExtractionJob result;

private slots:
	void pushButtonOK_Click();

};

#endif // FORMJOBMANAGEMENT_H
