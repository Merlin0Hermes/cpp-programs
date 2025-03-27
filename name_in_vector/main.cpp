#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string target{};
    std::cin >> target;

    for (auto name: names)
    {
        if (name == target)
            std::cout << target << " was found.\n";
    }

    return 0;
}