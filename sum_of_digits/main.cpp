#include <iostream>

int sum_digits(int n)
{
    if (n / 10 == 0)
        return n % 10;
    return sum_digits( n / 10) + n % 10;
}


int main()
{
    return 0;
}