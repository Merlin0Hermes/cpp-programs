// Program to print who is older among two people. Prompts the user for name and age

#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

std::string get_name(std::string_view message);

int main()
{

    std::string person_one = get_name("Enter the name of person #1: ");
    std::string person_two = get_name("Enter the name of person #2: ");

    std::cout << person_one << "\n" << person_two;


    return 0;
}

std::string get_name(std::string_view message)
{
    std::cout << message;
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}
