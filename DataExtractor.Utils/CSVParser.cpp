#include "CSVParser.h"

using namespace std;

CSVParser::CSVParser()
{
}


CSVParser::~CSVParser()
{
}


bool CSVParser::ParseUIntList(const std::string &p_listStr, std::list<unsigned int> &p_list)
{
	bool retVal = true;
	
	string numberTemp = "";
	size_t indexOf = 0;
	for (char c : p_listStr)
	{
		if (c >= '0' && c <= '9')
			numberTemp += c;
		else if(c != ' ' && c != ',')
		{
			retVal = false;
			break;
		}
		if (c == ',' || indexOf == p_listStr.size() - 1)
		{
			if (!numberTemp.empty())
			{
				p_list.push_back(stoul(numberTemp, nullptr, 0));
				numberTemp.clear();
			}
		}
		indexOf++;
	}

	return retVal;
}
