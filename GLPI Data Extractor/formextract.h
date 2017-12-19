#pragma once

#include <QWidget>
#include "ui_formextract.h"
#include "extractState.h"
#include "ExtractionJob.h"

class FormExtract : public QWidget
{
	Q_OBJECT

public:
	FormExtract(QWidget *parent = Q_NULLPTR);
	~FormExtract();
	ExtractState getState() const;
	void ExtractJob(const ExtractionJob &job);
private:
	Ui::FormExtract ui;
	QString m_currentTitle;
	ExtractionJob m_currentJob;
	ExtractState m_state;
	size_t m_currentJobIndex;
private slots:
	void loadfinished(bool ok);
};
