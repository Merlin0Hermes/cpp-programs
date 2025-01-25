// Program to print who is older among two people. Prompts the user for name and age

#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

std::string get_name(std::string_view message);
int get_age(std::string_view message);

int main()
{

    std::string person_one = get_name("Enter the name of person #1: ");
    int person_one_age = get_age("Enter the age of " + person_one + ": ");

    std::string person_two = get_name("Enter the name of person #2: ");
    int person_two_age = get_age("Enter the age of " + person_two + ": ");



    return 0;
}

int get_age(std::string_view message)
{

    std::cout << message;
    int age;
    std::cin >> age;

    return age;
}

std::string get_name(std::string_view message)
{
    std::cout << message;
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}
