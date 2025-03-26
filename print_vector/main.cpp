#include <iostream>
#include <vector>

template <typename T>
void print_array(const T& arr)
{
    for (std::size_t i {}; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    print_array(arr); // use function template to print array

    return 0;
}