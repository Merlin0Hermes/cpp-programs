// Program to print who is older among two people. Prompts the user for name and age

#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

std::string get_name(int num);
int get_age(std::string_view person);

void print_result(std::string_view name1, int age1,
                  std::string_view name2, int age2);

int main()
{

    const std::string person_one { get_name(1) };
    const int person_one_age { get_age(person_one) };

    const std::string person_two { get_name(2) };
    const int person_two_age { get_age(person_two) };

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


int get_age(std::string_view person)
{

    std::cout << "Enter the age of " << person << ": ";
    int age;
    std::cin >> age;

    return age;
}

std::string get_name(int num)
{
    std::cout << "Enter the age of person #" << num << ": ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}
