#include "WordCount.h"
#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> wordMap;

	ReadingAndCount(std::cin, wordMap);

	WriteMap(std::cout, wordMap);

	return 0;
}
