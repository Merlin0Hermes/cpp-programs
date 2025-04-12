// program to sort names using a dynamically allocated array

#include <iostream>
#include <string>
#include <cstddef>
#include <algorithm>

int main()
{
    std::size_t length{};
    std::cout << "How many names would you like to enter: ";
    std::cin >> length; 
    std::string * names { new std::string[length] };

    for (std::size_t i {0}; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + length);

    std::cout << "Here is you sorted list: \n";
    for (std::size_t i {0}; i < length; ++i)
    {
        std::cout << "Name #" << i + 1 << ": " << names[i] << "\n";
    }

    delete[] names;
    return 0;
}