// program to accept a number from user and print the double of that number

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double of that number is " << num * 2 << "\n";

	return 0;
}