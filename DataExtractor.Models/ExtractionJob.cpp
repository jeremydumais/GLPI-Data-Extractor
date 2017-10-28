#include "ExtractionJob.h"
#include <algorithm>

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

const string &ExtractionJob::getName() const
{
	return m_name;
}

void ExtractionJob::setName(const string &p_name)
{
	if (p_name.empty())
		throw invalid_argument("p_name");
	m_name = p_name;
}

size_t ExtractionJob::getTicketsCount() const
{
	return m_ticketIds.size();
}

void ExtractionJob::addTicketId(unsigned int p_ticketId)
{
	//Check if the ticket not already exist
	if (find(m_ticketIds.begin(), m_ticketIds.end(), p_ticketId) != m_ticketIds.end())
			throw invalid_argument("p_ticketId already exist in the list");
	m_ticketIds.push_back(p_ticketId);
}

void ExtractionJob::removeTicketId(unsigned int p_ticketId)
{
	//Check if the ticket already exist
	if (find(m_ticketIds.begin(), m_ticketIds.end(), p_ticketId) == m_ticketIds.end())
		throw invalid_argument("p_ticketId cannot be found in the list");
	m_ticketIds.remove(p_ticketId);
}

void ExtractionJob::clearTickets()
{
	m_ticketIds.clear();
}