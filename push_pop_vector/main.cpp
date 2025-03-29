#include <iostream>
#include <vector>

template <typename T=int>
class Stack
{
public:
    Stack(const std::vector<T>& vector): stack{vector}
    { }
    Stack() = default;
    
    void print_stack() const
    {
        std::cout << "\t(Stack:";

        for (const auto& element: stack)
            std::cout << " " << element;
        
        if (stack.empty())  
            std::cout << " empty"; 

        std::cout << ")\n";
    }


    void push(const T& element)
    {
        std::cout << "Push " << element;
        stack.push_back(element);
        print_stack();
    }

    void pop()
    {
        std::cout << "Pop ";
        stack.pop_back();
        print_stack();
    }

private:
    std::vector<T> stack{ };
};


int main()
{
    Stack stack{};

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    stack.push(4);

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}

