// basic calculator using function pointers

#include <iostream>

int get_number()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
}

char get_operator()
{
    std::cout << "Enter operator (+, -, *, /): ";
    char opt{};
    std::cin >> opt;

    return opt;
}


int main()
{
    get_number();
    get_operator();
    get_number();

    return 0;
}