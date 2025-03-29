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


template <typename T>
void push(std::vector<T>& stack, T element)
{
    std::cout << "Push " << element;
    stack.push_back(element);
    print_stack(stack);
}


template <typename T>
void pop(std::vector<T>& stack, T element)
{
    std::cout << "Pop " << element;
    stack.pop_back(element);
    print_stack(stack);
}


int main()
{
    std::vector<int> why{ };
    
    push(why, 5);
}

