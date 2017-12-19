#include "formextract.h"
#include <qsettings.h>

FormExtract::FormExtract(QWidget *parent)
	: QWidget(parent), m_state(ExtractState::Undefined), m_currentJob("<undefined>"), m_currentJobIndex(-1)
{
	ui.setupUi(this);
	connect(ui.webEngineView, &QWebEngineView::loadFinished, this, &FormExtract::loadfinished);
}

FormExtract::~FormExtract()
{
}

void FormExtract::loadfinished(bool ok)
{
	this->setWindowTitle(ui.webEngineView->title());
	m_currentTitle = ui.webEngineView->title();
	if (m_currentTitle == "GLPI - Authentication")
	{
		m_state = ExtractState::Authentication;
		ui.webEngineView->page()->runJavaScript("document.getElementById('login_name').value = 'normal_en'; document.getElementById('login_password').value = 'normal';document.getElementById('login_remember').checked = false; document.getElementsByName('submit')[0].remove(); document.getElementById('login_name').form.submit();", [](const QVariant &result) {});
	}
	else if(m_currentTitle == "GLPI - Standard Interface" && m_state == ExtractState::Authentication)
	{
		m_state = ExtractState::LoggedIn;
	}
	else if (m_state == ExtractState::Extracting)
	{
		//Extract the current ticket
		ui.webEngineView->page()->printToPdf(QString("C:\\Temp\\pdf")+ QString::number(m_currentJob.getTicketIds().at(m_currentJobIndex)) +QString(".pdf"));
		m_currentJobIndex++; 
		if (m_currentJobIndex < m_currentJob.getTicketsCount())
		{
			QSettings settings;
			QString glpiUrl = settings.value("GLPIUrl", "").toString();
			ui.webEngineView->load(QUrl(glpiUrl + "/front/ticket.form.php?id=" + QString::number(m_currentJob.getTicketIds().at(m_currentJobIndex)) + "&forcetab=-1"));		
		}
		else
			m_state = ExtractState::ExtractionJobComplete;
	}
}

ExtractState FormExtract::getState() const
{
	return m_state;
}

void FormExtract::ExtractJob(const ExtractionJob &job)
{
	m_currentJob = job;
	m_currentJobIndex = 0;
	m_state = ExtractState::Extracting;
	QSettings settings;
	QString glpiUrl = settings.value("GLPIUrl", "").toString();
	ui.webEngineView->load(QUrl(glpiUrl + "/front/ticket.form.php?id=" + QString::number(m_currentJob.getTicketIds()[m_currentJobIndex]) + "&forcetab=-1"));
}
