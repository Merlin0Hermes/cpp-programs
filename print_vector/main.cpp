#include <iostream>
#include <vector>
#include <string_view>
#include <limits>
#include <optional>

template <typename T>
void print_array(const T& arr)
{
    for (std::size_t i {}; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_number(std::string_view prompt)
{

    int number{};
    while (true)
    {
        std::cout << prompt;
        std::cin  >> number;
        
        if (!std::cin)
        {
            std::cin.clear();
            ignore_line();
        }
        else 
            break;

    }
    ignore_line();
    return number;
}


template <typename T>
std::optional<std::size_t> get_index(const std::vector<T>& arr, T element)
{
    for (std::size_t i {}; i < arr.size(); ++i)
    {
        if (arr[i] == element)
            return i;
    }
    return {};
}


int main()
{
    int num { get_number("Enter a number between 1 and 9: ") };

    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    print_array(arr);

    std::optional<int> index { get_index(arr, num) };
    if (index)
        std::cout << "The number " << num << " has index " << *get_index(arr, num) << "\n";
    else
        std::cout << "The number " << num << " was not found\n";

    return 0;
}