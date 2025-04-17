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

template<typename T, typename U>
std::vector<T> generate_numbers(T start, std::size_t n, U mult)
{
    std::vector<T> vec(n);
    for (std::size_t i {0}; i < n; ++i)
    {
        vec[i] = ((start * start) * mult);
        ++start;
    }    
    return vec;
}

template <typename T>
bool find_and_erase(std::vector<T>& vec, T element)
{
    auto found { std::find(vec.begin(), vec.end(), element) };

    if (found == vec.end())
        return false;
    vec.erase(found);
    return true;
}


void play_game(int start, int n)
{
    int mult { Random::get(Settings::min_mult, Settings::max_mult) };

    std::vector squares { generate_numbers(start, n, mult) };
    std::cout << "I generated " << n << " square numbers. Do you know what each number is after multiplying it by " << mult << "?\n";

    while (true)
    {
        int guess { get_num() };

        if (find_and_erase(squares, guess))
        {
            if (squares.empty())
                break;
            std::cout << "Nice! " << squares.size() << " number(s) left.\n";
        }
        else 
        {
            std::cout << guess << " is wrong! Try " << closest_element(squares, guess) << " next time.\n";
            return;
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