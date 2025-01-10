// Program to prompt the user for a single character and print its corresponding ASCII value

#include <iostream>

int char_to_int(char ch)
{
	return ch;
}

int main()
{
	char ch{};
	std::cout << "Enter a single character: ";
	std::cin >> ch;

	std::cout << "You entered '" << ch << "' , which has ASCII code " << char_to_int(ch) << ".\n";

	return 0;
}