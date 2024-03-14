
#include <iostream>
#include <map>

std::map<const std::string, const std::string> symbols{
	{ "&quot;", "\"" },
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" }
};

std::string ConvertToSymbol(const std::string code)
{
	return symbols[code] != "" ? symbols[code] : code;
}

std::string HtmlDecode(std::string const& html)
{

	std::string decodedHtml;
	size_t indexStart = 0, indexEnd = 0;

	while ((indexStart = html.find('&', indexStart)) != std::string::npos)
	{
		decodedHtml.append(html, indexEnd, indexStart - indexEnd);
		indexStart++;
		indexEnd = indexStart;

		if (html.find(';', indexEnd) != std::string::npos)
		{
			size_t lengthWordBetweenSymbols = html.find(';', indexEnd) - indexEnd;

			std::string code = "&";
			code.append(html, indexEnd, lengthWordBetweenSymbols);
			code += ";";

			code = ConvertToSymbol(code);
			decodedHtml += code;
			indexStart += lengthWordBetweenSymbols + 1;
			indexEnd = indexStart;
		}
		else
		{
			decodedHtml += '&';
			break;
		}
	}

	if (indexStart != html.length())
	{
		decodedHtml.append(html, indexEnd, html.length() - indexEnd);
	}
	return decodedHtml;
}