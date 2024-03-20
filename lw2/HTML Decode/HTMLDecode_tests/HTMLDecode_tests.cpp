#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/HTMLDecode.h"

SCENARIO("Test Decode ")
{
	WHEN("Input string is empty")
	{
		std::string inputString = "";
		THEN("Decoded string is empty")
		{
			std::string decodedString = HtmlDecode(inputString);
			CHECK(decodedString.empty());
		}
	}

	WHEN("Input string has no html-entities")
	{
		std::string inputString = "string";
		std::string resultString = "string";
		THEN("Decoded string as input")
		{
			std::string decodedString = HtmlDecode(inputString);
			CHECK(decodedString == resultString);
		}
	}

	WHEN("Input string has all html-entities")
	{
		std::string inputString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
		std::string resultString = "Cat <says> \"Meow\". M&M's";
		THEN("Decoded string is Cat <says> \" Meow \". M&M's")
		{
			std::string decodedString = HtmlDecode(inputString);
			CHECK(decodedString == resultString);
		}
	}	

	WHEN("Input string has the form \"&&&&&&&&&&&&&&&&&&&&&&;\"")
	{
		std::string inputString = "&&&&&&&&&&&&&&&&&&&&&&;";
		std::string resultString = "&&&&&&&&&&&&&&&&&&&&&&;";
		THEN("Decoded string is \"&&&&&&&&&&&&&&&&&&&&&&;\"")
		{
			std::string decodedString = HtmlDecode(inputString);
			CHECK(decodedString == resultString);
		}
	}
}