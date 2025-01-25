#include <iostream>

constexpr bool is_even(int num)
{
    return num % 2 == 0;
}

int main()
{
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    if (is_even(number))
    {
        std::cout << number << " is even.\n";
    }
    else
    {
        std::cout << number << " is odd.\n";
    }
    return 0;

}
