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
    do 
    {
        std::cin.clear();
        ignore_line();
        std::cout << prompt;
        std::cin  >> number;

    } while(!std::cin);

    ignore_line();
    return number;

}

template <typename T>
std::optional<T> get_index(const std::vector<T>& arr, T element)
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
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    print_array(arr); // use function template to print array

    return 0;
}