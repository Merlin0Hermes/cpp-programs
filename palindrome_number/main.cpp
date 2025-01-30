#include <iostream>
#include <cstdint>

bool is_palindrome(std::int64_t n)
{
    std::int64_t reverse{ }, original{ n };
    int digit{ };

    while (n != 0)
    {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    return reverse == original;
}


int main()
{
    std::cout << "Enter a number: ";
    std::int64_t number{ };
    std::cin >> number;


    if (is_palindrome(number))
        std::cout << number << " is a palindrome.\n";
    else
        std::cout << number << " is not a palindrome.\n";

    return 0;
}
