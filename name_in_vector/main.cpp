#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T, typename U>
bool is_value_in_array(const std::vector<T>& arr, const U& value)
{
    for (const auto& element: arr)
    {
        if (element == value)
            return true;
    }
    return false;
}


int main()
{
    static const std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave",
                "Emily", "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: ";
    std::string target{};
    std::cin >> target;
    
    if (is_value_in_array(names, target))
        std::cout << target << " was found.\n";
    else
        std::cout << target << " was not found.\n";

    return 0;
}