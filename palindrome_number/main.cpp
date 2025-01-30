#include <iostream>
#include <cstdint>

int main()
{
    std::int64_t n{ }, reverse { }, original{ };
    int digit{ };
    std::cout << "Enter the number: ";
    std::cin >> original;

    n = original;

    while (n != 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    if (original == reverse)
        std::cout << original << " is a palindrome.\n";
    else
        std::cout << original << " is not a palindrome.\n";
}
