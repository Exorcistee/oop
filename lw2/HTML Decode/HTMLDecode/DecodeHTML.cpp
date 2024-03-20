
#include <iostream>
#include <map>

std::map<const std::string, const std::string> symbols
{
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
// Исправить на map.at

std::string HtmlDecode(std::string const& html)
{

	std::string decodedHtml;
	size_t indexStart = 0, indexEnd = 0;

	while ((indexEnd = html.find('&', indexEnd)) != std::string::npos)
	{
		decodedHtml.append(html, indexStart, indexEnd - indexStart);
		indexEnd++;
		indexStart = indexEnd;

		if (html.find(';', indexStart) != std::string::npos)
		{
			size_t lengthWordBetweenSymbols = html.find(';', indexStart) - indexStart;

			std::string code = "&";
			code.append(html, indexStart, lengthWordBetweenSymbols);
			code += ";";
			code = ConvertToSymbol(code);
			decodedHtml += code;
			indexEnd += lengthWordBetweenSymbols + 1;
			indexStart = indexEnd;
		}
		else
		{
			decodedHtml += '&';
			break;
		}
	}

	if (indexStart != html.length())
	{
		decodedHtml.append(html, indexStart, html.length() - indexStart);
	}

	return decodedHtml;
}