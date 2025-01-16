// program that asks the user to enter their full name and age.
// Outputs sum of their age and the number of characters in their name
// spaces are counted

#include <iostream>
#include <string>

int main()
{

	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter you age: ";
	int age{};
	std::cin >> age;

	std::cout << "Your age + length of name is: ";
	std::cout << static_cast<int>(name.length()) + age << "\n";

	
	return 0;
}

