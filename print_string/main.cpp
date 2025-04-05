// program to print C-style string

#include <iostream>
#include <cassert>

void print_str_reverse(const char * str);

void print_str(const char * str, bool reverse = false)
{
    if (reverse)
    {
        print_str_reverse(str);   
        return;
    }
    while (*str != '\0')
    {
        std::cout << *str;
        ++str;
    }
}

void print_str_reverse(const char * str)
{
    const char * ptr{str};
    for (; *ptr != '\0'; ++ptr)
        ;

    while (ptr-- != str)
        std::cout << *ptr;
}

int main()
{
    print_str("\nHello, world!", true);
    return 0;
}