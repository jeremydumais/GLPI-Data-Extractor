#include "ExtractionJob.h"
#include <algorithm>

using namespace std;

//Constructor
ExtractionJob::ExtractionJob(const string &p_name)
	: m_name(p_name)
{
	if (p_name.empty())
		throw invalid_argument("p_name");
}

//Destructor
ExtractionJob::~ExtractionJob()
{
}

//Copy constructor
ExtractionJob::ExtractionJob(const ExtractionJob &p_job)
	: m_name(p_job.m_name), m_ticketIds(p_job.m_ticketIds)
{
}

//Move constructor
ExtractionJob::ExtractionJob(ExtractionJob &&p_job)
	: m_name(move(p_job.m_name)), m_ticketIds(move(p_job.m_ticketIds))
{
	p_job.m_name = "<undefined>";
	p_job.m_ticketIds.clear();
}

//Copy assignment
ExtractionJob &ExtractionJob::operator=(const ExtractionJob &p_job)
{
	m_name = p_job.m_name;
	copy(p_job.m_ticketIds.begin(), p_job.m_ticketIds.end(), back_inserter(m_ticketIds));
	return *this;
}

//Move assignment
ExtractionJob &ExtractionJob::operator=(ExtractionJob &&p_job)
{
	swap(m_name, p_job.m_name);
	swap(m_ticketIds, p_job.m_ticketIds);
	return *this;
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

const list<unsigned int> ExtractionJob::getTicketIds() const
{
	return m_ticketIds;
}

void ExtractionJob::setTicketIds(const std::list<unsigned int> &p_ticketIds)
{
	m_ticketIds = p_ticketIds;
}
