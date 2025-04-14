// basic calculator using function pointers

#include <iostream>
#include <limits>

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_number()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
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


int main()
{
    get_number();
    get_operator();
    get_number();

    return 0;
}