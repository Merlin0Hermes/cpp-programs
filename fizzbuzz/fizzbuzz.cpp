// program to print fizz buzz pop depending upon divisibility of numbers
// fizz = divisible by 3
// buzz = divisible by 5
// pop = divisible by 7


#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

void fizzbuzz(int n)
{
    const std::vector<std::string_view> words {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    const std::vector<int> divisors {3, 5, 7, 11, 13, 17, 19}; // mapping between words and divisors

    assert(words.size() == divisors.size());

    for (int i{ 1 }; i <= n; ++i)
    {
        bool outputted { false };
        for (std::size_t j{ }; j < divisors.size(); ++j)
        {
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                outputted = true;
            } 
        }
        if (!outputted)
            std::cout << i;
        std::cout << "\n";
    }


}

int main()
{
    fizzbuzz(150);
}