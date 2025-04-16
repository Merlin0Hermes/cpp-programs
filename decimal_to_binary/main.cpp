#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <boost/dynamic_bitset.hpp>  // boost library for dynamic bitset


std::size_t bits_needed(std::uint64_t n)
{

    if (n == 0 || n == 1)
        return 1;

    std::size_t size { static_cast<std::size_t>(std::floor(std::log2(n)))};
    return (size == 64) ? size : size + 1;

}

auto to_binary(std::uint64_t n)
{
    std::size_t bit { bits_needed(n) };
    
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