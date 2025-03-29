#include <iostream>
#include <vector>

template <typename T>
void print_stack(const std::vector<T>& stack)
{
    std::cout << "\t(Stack:";

    for (const auto& element: stack)
        std::cout << " " << element;
    
    if (stack.empty())  
        std::cout << " empty"; 

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
void pop(std::vector<T>& stack)
{
    std::cout << "Pop ";
    stack.pop_back();
    print_stack(stack);
}


int main()
{
    std::vector<int> stack{ };

    print_stack(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    pop(stack);
    push(stack, 4);

    pop(stack);
    pop(stack);
    pop(stack);

    return 0;

}

