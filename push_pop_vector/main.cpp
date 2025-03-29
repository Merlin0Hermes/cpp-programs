#include <iostream>
#include <vector>

template <typename T>
void print_stack(const std::vector<T>& stack)
{
    std::cout << "\t(Stack:";

    if (stack.empty())  
        std::cout << " empty";
    else
    {
        for (const auto& element: stack)
        {
            std::cout << " " << element;
        }
    }
    std::cout << ")\n";
}

