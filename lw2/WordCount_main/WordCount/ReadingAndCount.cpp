#include <algorithm>
#include <cctype>
#include <map>
#include <sstream>
#include <string>
#include <iostream>

std::string toLowerCase(std::string& word)
{
	std::transform(begin(word), end(word), begin(word),
		[](unsigned char c) { return std::tolower(c); });
	return word;
}

void ReadingAndCount(std::istream& input, std::map<std::string, int>& wordMap)
{
	std::string line;
	while (std::getline(input, line))
	{

		std::istringstream iss(line);
		std::string word;

		while (iss >> word)
		{
			++wordMap[toLowerCase(word)];
		}
	}
}