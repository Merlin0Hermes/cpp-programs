// program to print C-style string

#include <cstddef>
#include <iostream>
#include <cassert>

void print_str(char * str)
{
    assert(*str != '\0' && "string cannot be empty.");
    for (char* ptr{str}; *ptr != '\n'; ptr++)
    {
        std::cout << *ptr;
    }
}