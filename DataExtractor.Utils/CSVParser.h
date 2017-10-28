#pragma once

#include <string>
#include <list>

class __declspec(dllexport) CSVParser
{
public:
	CSVParser();
	~CSVParser();

	static bool ParseUIntList(const std::string &p_listStr, std::list<unsigned int> &p_list);
};

