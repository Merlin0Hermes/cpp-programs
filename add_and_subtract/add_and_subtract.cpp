// program to prompt user for 2 numbers and display result of addition and subtraction on them.

#include <iostream>

int main()
{
	
	std::cout << "Enter an integer: ";
	int a{ };
	std::cin >> a;

	std::cout << "Enter another integer: ";
	int b{ };
	std::cin >> b;

	std::cout << a << " + " << b << " = " << a + b << ".\n";
	std::cout << a << " - " << b << " = " << a - b << ".\n";

	return 0;
}