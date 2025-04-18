#include <iostream>
#include <cstdint>
#include <ostream>

class Average
{
public:
    Average(int sum = 0, int total = 0): m_sum(sum), m_total(total) { }
    
    friend std::ostream& operator<< (std::ostream& out, const Average& avg);
    Average& operator+= (std::int32_t n);

private:
    std::uint32_t m_sum{};
    int m_total{};
};


std::ostream& operator<< (std::ostream& out, const Average& avg)
{
    return out << (static_cast<double>(avg.m_sum) / avg.m_total);
}

Average& Average::operator+= (std::int32_t n)
{
    m_sum += n;
    ++m_total;

    return *this;
}

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}