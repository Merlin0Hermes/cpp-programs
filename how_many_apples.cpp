#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(int n)
{
    if (n < 0)
    {
        return "negative";
    }
    else if (n == 0)
    {
        return "no";
    }
    else if (n == 1)
    {
        return "a single";
    }
    else if (n == 2)
    {
        return "a couple of";
    }
    else if (n == 3)
    {
        return "a few";
    }
    else 
    {
        return "many";
    }

}

// Write the function getApplesPluralized() here

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}