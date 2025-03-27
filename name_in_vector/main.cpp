#include <iostream>
#include <vector>
#include <string>
#include <string_view>

int main()
{
    static const std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave",
                "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string target{};
    std::cin >> target;

    bool found { false };
    for (auto name: names)
    {
        if (name == target)
        {
            found = true;
            break;
        }
    }
    if (found)
        std::cout << target << " was found.\n";
    else
        std::cout << target << " was not found.\n";

    return 0;
}