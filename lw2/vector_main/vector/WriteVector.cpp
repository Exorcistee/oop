#include "Vector.h"

void WriteVector(std::vector<double>& numbers, std::ostream& output)
{
	std::copy(begin(numbers), end(numbers), std::ostream_iterator<double>(output, " "));
}