#include <iostream>
#include <cassert>
#include <cstdint>


class FixedPoint2
{
    FixedPoint2(std::int16_t number, std::int8_t fractional)
    :m_number(number)
    ,m_fractional(fractional)
    {
    }

    

private:
    std::int16_t m_number{};
    std::int8_t m_fractional{};
};



int main()
{
	FixedPoint2 a{ 34, 56 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{ -2, 8 };
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{ 2, -8 };
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{ -2, -8 };
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{ 0, -5 };
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{ 0, 10 };
	assert(static_cast<double>(f) == 0.1);

	return 0;
}