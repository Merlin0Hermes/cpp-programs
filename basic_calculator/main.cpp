// basic calculator using function pointers

#include <cassert>
#include <iostream>
#include <limits>
#include <functional>

using ArithmeticFunction = std::function<int (int, int)>;

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_number()
{
    while (true)
    {
        std::cout << "Enter an integer: ";
        int num{};
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();
            ignore_line();
            continue;
        }

        return num;
    }
}

char get_operator()
{
    while (true)
    {
        std::cout << "Enter operator (+, -, *, /): ";
        char opt{};
        std::cin >> opt;    
        
        if (!std::cin)
        {
            std::cin.clear();
            ignore_line();
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            ignore_line();
            continue;
        }

        switch (opt) 
        {
            case '+': case '-':
            case '*': case '/':
                return opt;
            default:
                ignore_line();
                continue;
        }
    }
}


int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    assert(b != 0 && "can't divide by 0");
    
    return a / b;
}

ArithmeticFunction get_arithmetic_function(char opt)
{
    switch(opt)
    {
        case '+':
            return &add;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
    }
    return nullptr;
}

int main()
{
    get_number();
    get_operator();
    get_number();

    return 0;
}