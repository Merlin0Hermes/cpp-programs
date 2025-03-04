// program to print fizz buzz pop depending upon divisibility of numbers
// fizz = divisible by 3
// buzz = divisible by 5
// pop = divisible by 7


#include <iostream>

void fizzbuzz(int n)
{
    for (int i{ 1 }; i <= n; ++i)
    {
        bool printed{ false };
        if (i % 3 == 0)
        {
            std::cout << "fizz";
            printed = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "buzz";
            printed = true;
        }
        if (i % 7 == 0)
        {
            std::cout << "pop";
            printed = true;
        }
        if (!(printed))
        {
            std::cout << i;
        }
        std::cout << "\n";
    }
}

int main()
{
    fizzbuzz(150);
}