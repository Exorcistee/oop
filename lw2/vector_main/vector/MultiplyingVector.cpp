#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <vector>

void MultiplyingVector(std::vector<double>& numbers)
{
	if (numbers.empty())
	{
		return;
	}

	auto minMax = std::minmax_element(begin(numbers), end(numbers));
	double max = *minMax.second;
	double min = *minMax.first;
	double multiplicationMaxMin = max * min;
	
	std::transform(begin(numbers), end(numbers), begin(numbers), [multiplicationMaxMin](double x) {
		return x < 0 ? x * multiplicationMaxMin : x; });
}