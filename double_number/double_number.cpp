// program to accept a number from user and print the double and triple of that number

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double of " << num << " is " << num * 2 << "\n";
	std::cout << "Triple of " << num << " is " << num * 3 << "\n";

	return 0;
}