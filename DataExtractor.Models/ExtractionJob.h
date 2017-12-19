#pragma once
#define DllExport __declspec(dllexport)   

#include <string>
#include <vector>

class ExtractionJob
{
public:
	DllExport ExtractionJob(const std::string &p_name); //COnstructor
	DllExport virtual ~ExtractionJob();	//Destructor
	DllExport ExtractionJob(const ExtractionJob &p_job); //Copy constructor
	DllExport ExtractionJob(ExtractionJob &&p_job); //Move constructor

	DllExport ExtractionJob &operator=(const ExtractionJob &p_job); //Copy assignment
	DllExport ExtractionJob &operator=(ExtractionJob &&p_job); //Move assignment

	DllExport const std::string &getName() const;
	DllExport const std::vector<size_t> getTicketIds() const;
	DllExport size_t getTicketsCount() const;

	DllExport void setName(const std::string &p_name);
	DllExport void setTicketIds(const std::vector<size_t> &p_ticketIds);
	DllExport void addTicketId(size_t p_ticketId);
	DllExport void removeTicketId(size_t p_ticketId);
	DllExport void clearTickets();

private:
	std::string m_name;
	std::vector<size_t> m_ticketIds;
};