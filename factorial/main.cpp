#include <iostream>
#include <cstdint>

std::int64_t factorial(int n)
{
    if (n <= 0)
        return 1;
    return n * factorial(n - 1);
}


int main()
{
    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;

    std::cout << "Factorial of " << num << " is " << factorial(num) << "\n";
    return 0;
}