#include <iostream>
#include <cmath>

int count_digits(int n)
{
    int count = 0;
    for (; n != 0; count++)
        n /= 10;

    return count;
}


bool is_armstrong(int n)
{
    int original = n, count;

    count = count_digits(n);

    int sum = 0, digit;
    while (n != 0)
    {
        digit = n % 10;
        sum += std::pow(digit, count);
        n /= 10;
    }
    return sum == original;
}


int main()
{
    std::cout << "Enter the number: ";
    int number;
    std::cin >> number;

    if (is_armstrong(number))
        std::cout << number << " is an Armstrong number.\n";
    else
        std::cout << number << " is not an Armstrong number.\n";

    return 0;
}