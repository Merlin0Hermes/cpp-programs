// program to print C-style string

#include <iostream>
#include <cassert>

void print_str(const char * str)
{
    assert(*str != '\0' && "string cannot be empty.");
    for (int i{0}; *(str + i) != '\0'; ++i)
    {
        std::cout << *(str + i);
    }
}


int main()
{
    print_str("Hello, world!\n");
    return 0;
}