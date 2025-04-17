#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include "../Random.h"


namespace Settings 
{
    constexpr int min_mult{2}; // inclusive
    constexpr int max_mult{4}; // inclusive
}


int get_num()
{
    while (true)
    {
        int num{};
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        return num;
    }
}

template<typename T>
T closest_element(const std::vector<T>& vec, T n)
{
    return *std::min_element(vec.begin(), vec.end(),
    [n](T a, T b)
    {
        return std::abs(a - n) < std::abs(b - n);
    });
}


void play_game(int start, int n)
{
    int mult { Random::get(Settings::min_mult, Settings::max_mult) };

    std::vector<int> squares(n);
    
    for (int i {0}; i < n; ++i)
    {
        squares[i] = ((start * start) * mult);
        ++start;
    }

    std::cout << "I generated " << n << " square numbers. Do you know what each number is after multiplying it by " << mult << "?\n";

    while (true)
    {
        int guess { get_num() };
        auto found { std::find(squares.begin(), squares.end(), guess) };

        if (found == squares.end())
        {
            std::cout << guess << " is wrong! Try " << closest_element(squares, guess) << " next time.\n";
            return;
        }
        else 
        {
            squares.erase(found);
            if (squares.empty())
                break;
            std::cout << "Nice! " << squares.size() << " number(s) left.\n";
        }
    }
    std::cout << "Nice! You found all numbers, good job!\n";

}


int main()
{
    std::cout << "Start where? ";
    int start { get_num() };
    
    std::cout << "How many? ";
    int quantiy { get_num() };

    play_game(start, quantiy);

    return 0;
}