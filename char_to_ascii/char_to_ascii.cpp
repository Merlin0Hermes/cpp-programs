// Program to prompt the user for a single character and print its corresponding ASCII value


#include <iostream>

int main()
{
	char ch{};
	std::cout << "Enter a single character: ";
	std::cin >> ch;

	std::cout << "You entered '" << ch << "' , which has ASCII code " << static_cast<int>(ch) << ".\n";

	return 0;
}