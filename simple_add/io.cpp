#include "io.h"
#include <iostream>

int read_number()
{
	std::cout << "Enter an integer to add: ";

	int num{ };
	std::cin >> num;

	return num;
}


void write_answer(int n)
{
	std::cout << "Answer: " << n << "\n";
}