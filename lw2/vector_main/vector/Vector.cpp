// ������� 4 : �������� ������ ������������� ������� ������� �� ������������ ������������� �
//			������������ ��������� ��������� �������
//			��������� : ����������� std::minmax_element
//			, ����� ����� ����������� � ������������ �������� �������

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