// Вариант 4 : Умножить каждый отрицательный элемент массива на произведение максимального и
//			минимального элементов исходного массива
//			Подсказка : используйте std::minmax_element
//			, чтобы найти минимальный и максимальный элементы массива

#include "Vector.h"
#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
	std::vector<double> numbers;

	ReadVector(numbers, std::cin);

	MultiplyingVector(numbers);

	std::sort(begin(numbers), end(numbers));

	WriteVector(numbers, std::cout);

}