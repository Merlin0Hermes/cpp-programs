#include <iostream>

void to_binary(int n)
{
    if (n == 0)
        return;
    to_binary(n / 2);
    std::cout << n % 2;
}


int main()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    to_binary(num);
}