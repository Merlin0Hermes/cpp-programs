#include <cctype>
#include <iostream>
#include <limits>


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


int main()
{
    std::cout << get_num();

    return 0;
}