#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <iostream>
#include <cmath>
#include <boost/dynamic_bitset.hpp>  // boost library for dynamic bitset


int bits_needed(unsigned int n)
{
    if (n < 0)
        n = -n;

    if (n == 0 || n == 1)
        return 1;

    return static_cast<int>(std::floor(std::log2(n))) + 1;

}

auto to_binary(unsigned int n)
{
    int bit { bits_needed(n) };
    
    boost::dynamic_bitset<> bits(bit);
    
    while (n != 0)
    {
        --bit;
        if (n % 2)
            bits.set(bit);
        n /= 2;
    }

    return bits;
}


int main()
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    auto binary { to_binary(num) };
    
    for (std::size_t i{0}; i < binary.size(); ++i)
        std::cout << binary[i];
    

    std::cout << "\n";

    return 0;
}