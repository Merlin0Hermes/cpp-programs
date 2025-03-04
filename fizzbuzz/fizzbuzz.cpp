// program to print fizz buzz pop depending upon divisibility of numbers
// fizz = divisible by 3
// buzz = divisible by 5
// pop = divisible by 7


#include <iostream>

void fizzbuzz(int n)
{
    constexpr int limit{ 20 };
    for (int i{ 1 }; i <= limit; ++i)
    {

        if (i % 3 == 0)
        {
            std::cout << "fizz\n";
        }
        if (i % 5 == 0)
        {
            std::cout << "buzz\n";
        }
        if (i % 7 == 0)
        {
            std::cout << "pop\n";
        }
        if (!(i % 3 == 0 || i % 5 == 0 || i % 7 == 0))
        {
            std::cout << i << "\n";
        }
    }
}

int main()
{
    fizzbuzz(5);
}