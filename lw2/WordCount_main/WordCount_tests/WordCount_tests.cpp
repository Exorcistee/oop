#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../WordCount/WordCount.h"
#include <sstream>

SCENARIO(" Test ReadingAndCount ")
{
	WHEN(" INPUT IS EMPTY ")
	{	
		std::map<std::string, int> wordMap;
		std::istringstream input("");
		THEN("Map is empty")
		{	
			ReadingAndCount(input, wordMap);
			CHECK(wordMap.empty());
			CHECK(input.eof());
		}
	}

	WHEN("Input contains various words")
	{
		std::map<std::string, int> wordMap, result = { { "123", 1 }, { "qwerty", 1 }, 
			{ "alo", 1 }, { "ola", 1 } };
		std::istringstream input("123 qwerty alo ola\n");
		THEN(" Map contains the same words and their count")
		{
			ReadingAndCount(input, wordMap);
			CHECK(input.eof());
			CHECK(wordMap == result);
		}
	}
	WHEN("input contains different and identical words")
	{
		std::map<std::string, int> wordMap, result = { { "alo", 4 }, { "ola", 1 }, { "qwerty", 1 }, 
			{ "ало", 4 }, { "кверти", 1 }, { "ола", 1 } };
		std::istringstream input("ало ола alo ola ало ало ало alo alo alo qwerty кверти\n");
		THEN(" Map contains the same words and their count")
		{
			ReadingAndCount(input, wordMap);
			CHECK(input.eof());
			CHECK(wordMap == result);
		}
	}
	WHEN("input contains identical words of different case")
	{
		std::map<std::string, int> wordMap, result = { { "alo", 5 } };
		std::istringstream input("alo Alo aLo alO ALO\n");
		THEN(" Map contains the same word")
		{
			ReadingAndCount(input, wordMap);
			CHECK(input.eof());
			CHECK(wordMap == result);
		}	
	}
}
SCENARIO("Test WriteMap")
{
	WHEN(" Map is empty")
	{
		std::map<std::string, int> wordMap;
		std::ostringstream output("");
		THEN("Output is empty")
		{
			WriteMap(output, wordMap);
			CHECK(output.str().empty());
		}
	}
	WHEN(" Map is't empty")
	{
		std::map<std::string, int> wordMap = { { "alo", 4 }, { "qwerty", 1 }, { "ало", 4 } };
		std::ostringstream output;
		THEN("Output is't empty")
		{
			WriteMap(output, wordMap);
			CHECK(output.str() == "alo: 4\nqwerty: 1\nало: 4\n");
		}
	}
}
