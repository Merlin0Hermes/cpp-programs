// Program to print who is older among two people. Prompts the user for name and age

#include <iostream>
#include <string>
#include <string_view>
#include <iomanip>

std::string get_name(std::string_view message);
int get_age(std::string_view message);
void print_result(std::string_view older_name, int old_age,
                  std::string_view younger_name, int young_age);

int main()
{

    std::string person_one = get_name("Enter the name of person #1: ");
    int person_one_age = get_age("Enter the age of " + person_one + ": ");

    std::string person_two = get_name("Enter the name of person #2: ");
    int person_two_age = get_age("Enter the age of " + person_two + ": ");

    if (person_one_age > person_two_age)
    {
        print_result(person_one, person_one_age, person_two, person_two_age);
    }
    else if (person_two_age > person_one_age)
    {
        print_result(person_two, person_two_age, person_one, person_one_age);
    }
    else
    {
        std::cout << "Both are the same age.\n";
    }


    return 0;
}

void print_result(std::string_view older_name, int old_age,
                  std::string_view younger_name, int young_age)
{
    std::cout << older_name << " (age " << old_age << ") is older than " << younger_name << " (age " << young_age << ").\n";
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
