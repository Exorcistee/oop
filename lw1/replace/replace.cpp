
#include "stdafx.h"

// Возвращает результат замены всех вхождения строки searchString внутри строки subject на replacementString
// Если строка searchString пустая, то возвращается subject
std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	size_t pos = 0;

	std::string result; // если искомая строка пустая, то функция возвращает исходный текст, сейчас пустая строка, В тестах должно проверятся

	if (searchString.length())
	{
		while (pos < subject.length())

		{
			size_t foundPos = subject.find(searchString, pos);

			if (foundPos != std::string::npos)
			{
				result.append(subject, pos, foundPos - pos); // Переписать чтобы вызовов append было 2, Вместо 3
				result += replacementString;
				pos = foundPos + searchString.length();
			}
			else
			{
				result.append(subject, pos, subject.length() - pos);
				break;
			}
		}
	}
	else
	{
		result = subject;
	}
	return result;
}

void GetResult(const std::string& inputFileName, const std::string& outputFileName,
	const std::string& searchString, const std::string& replacmentString)
{

	std::ifstream inputFile;
	inputFile.open(inputFileName);

	if (!inputFile.is_open())
	{
		printf("Something is wrong with the input file"); // не использовать принтф
	}

	std::ofstream outputFile;
	outputFile.open(outputFileName);

	if (!outputFile.is_open())
	{
		printf("Something is wrong with the output file"); // не использовать принтф

	}

	std::string search = searchString;
	std::string replace = replacmentString;

	CopyFileWithReplacement(inputFile, outputFile, search, replace);

	outputFile.flush(); // нужно проверять успешность выхзова flush
}

void CopyFileWithReplacement(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string line;

	while (std::getline(input, line))
	{
		// обрабатывать ошибку записи
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
	// надо проверить успешно ли завершилось чтение файла
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid argument count\n"
				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	std::string inputFileName, outputFileName, search, replace;

	inputFileName = argv[1];
	outputFileName = argv[2];
	search = argv[3];
	replace = argv[4];

	// Написать функцию принимающую имя входного и выходного файла, искомую строку и строку для замены и выполняет всю работу

	GetResult(inputFileName, outputFileName, search, replace);

	return 0;
}
