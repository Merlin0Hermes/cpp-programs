// program to print C-style string

#include <iostream>
#include <cassert>

void print_str(const char * str)
{
    while (*str != '\0')
    {
        std::cout << *str;
        ++str;
    }
}


int main()
{
    print_str("Hello, world!\n");
    return 0;
}