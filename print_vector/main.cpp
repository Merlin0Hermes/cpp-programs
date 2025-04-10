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

template <typename T>
T get_number(std::string_view prompt, T low, T high)
{
    T num{};
    do
    {
        std::cout << prompt;
        std::cin  >> num;
        
        if (!std::cin)
            std::cin.clear();
        ignore_line();

    } while (num < low || num > high);

    return num;
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
    auto num { get_number("Enter a number between 1 and 9: ", 1, 9) };

    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    print_array(arr);

    std::optional<std::size_t> index { get_index(arr, num) };
    if (index)
        std::cout << "The number " << num << " has index " << *index << "\n";
    else
        std::cout << "The number " << num << " was not found\n";

    return 0;
}