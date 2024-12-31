#include <iostream>

int read_number();
void write_answer(int n);

int main()
{
	std::cout << "Adds two numbers.\n";

	int a{ read_number() };
	int b{ read_number() };

	write_answer(a + b);

	return 0;
}


int read_number()
{
	std::cout << "Enter an integer: ";
	
	int num { };
	std::cin >> num;

	return num;
}


void write_answer(int n)
{
	std::cout << "Answer: " << n << "\n";
}