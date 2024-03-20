#pragma once
#include <map>
#include <string>

void ReadingAndCount(std::istream& input, std::map<std::string, int>& wordMap);
void WriteMap(std::ostream& output, std::map<std::string, int>& wordMap);
