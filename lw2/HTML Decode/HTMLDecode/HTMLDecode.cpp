#include "HTMLDecode.h"
#include <iostream>
#include <string>

int main()
{
	std::string HTML;
	while (std::getline(std::cin, HTML))
	{
		std::string decodedHTML = HtmlDecode(HTML);
		std::cout << decodedHTML << std::endl;

	}

	return 0;
}