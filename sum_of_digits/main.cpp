#include <iostream>
#include <cstdint>

int sum_digits(std::int64_t n)
{
    if (n / 10 == 0)
        return n % 10;
    return sum_digits( n / 10) + n % 10;
}


int main()
{
    std::cout << "Enter a number: ";
    std::int64_t num{};
    std::cin >> num;

    std::cout << "Sum of digits of " << num << " is " << sum_digits(num) << "\n";

    return 0;
}