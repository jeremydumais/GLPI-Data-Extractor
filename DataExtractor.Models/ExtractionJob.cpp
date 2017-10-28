#include "ExtractionJob.h"

using namespace std;

ExtractionJob::ExtractionJob(const string &p_name)
	: m_name(p_name)
{
	if (p_name.empty())
		throw invalid_argument("p_name");
}

ExtractionJob::~ExtractionJob()
{
}

const string &ExtractionJob::getName()
{
	return m_name;
}

void ExtractionJob::setName(const string &p_name)
{
	if (p_name.empty())
		throw invalid_argument("p_name");
	m_name = p_name;
}

size_t ExtractionJob::getTicketsCount()
{
	return m_ticketIds.size();
}

void ExtractionJob::addTicketId(unsigned int p_ticketId)
{
	m_ticketIds.push_back(p_ticketId);
}

void ExtractionJob::removeTicketId(unsigned int p_ticketId)
{

}