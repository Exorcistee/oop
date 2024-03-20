#include <iostream>
#include <map>
#include <string>

void WriteMap(std::ostream& output, std::map<std::string, int>& wordMap)
{
	for (const auto& pair : wordMap)
	{
		output << pair.first << ": " << pair.second << std::endl;
	}
}