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

	const ExtractionJob &getResult() const;
	void PrepareUpdateData(std::list<ExtractionJob> &p_actualList, const std::string &p_jobNameToUpdate);

private:
	Ui::FormJobManagement ui;
	FormManagementType m_formAction;
	ExtractionJob m_result;
	std::list<ExtractionJob> m_actualList;
	std::string m_jobNameToUpdate;

private slots:
	void pushButtonOK_Click();

};

#endif // FORMJOBMANAGEMENT_H
