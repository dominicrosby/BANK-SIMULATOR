#include "strlib.h"
#include <fstream>


std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	//new vector and entry format that contains each pieve of stock info
	std::vector<std::string> stockSections;
	std::string section = "";

	//iterate through input string
	for(int i = 0; i<str.length(); i++)
	{
		if(i+1 == str.length())
		{
			section +=str[i];
			stockSections.push_back(section);
		}
		//check for splitter
		else if(str[i]==splitChar)
		{
			stockSections.push_back(section);
			section = "";
		}
		//add everything else
		else
		{
			section +=str[i];
		}
	}
	return stockSections;
}