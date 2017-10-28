#pragma once
#include <string>
#include <list>

class __declspec(dllexport) ExtractionJob
{
public:
	ExtractionJob(const std::string &p_name);
	~ExtractionJob();

	const std::string &getName() const;
	size_t getTicketsCount() const;

	void setName(const std::string &p_name);
	void addTicketId(unsigned int p_ticketId);
	void removeTicketId(unsigned int p_ticketId);
	void clearTickets();

private:
	std::string m_name;
	std::list<unsigned int> m_ticketIds;
};