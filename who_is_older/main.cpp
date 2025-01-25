// Program to print who is older among two people. Prompts the user for name and age

#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

std::string get_name(std::string_view message);
int get_age(std::string_view message);

void print_result(std::string_view name1, int age1,
                  std::string_view name2, int age2);

int main()
{

    std::string person_one = get_name("Enter the name of person #1: ");
    int person_one_age = get_age("Enter the age of " + person_one + ": ");

    std::string person_two = get_name("Enter the name of person #2: ");
    int person_two_age = get_age("Enter the age of " + person_two + ": ");

    print_result(person_one, person_one_age, person_two, person_two_age);

    return 0;
}

void print_result(std::string_view name1, int age1,
                  std::string_view name2, int age2)
{
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ").\n";
    else if (age2 > age1)
        std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ").\n";
    else
        std::cout << name1 << " (age " << age1 << ") is of same age as " << name2 << " (age " << age2 << ").\n";


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
