#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>


class FixedPoint2
{
public:
    FixedPoint2(std::int16_t base, std::int8_t fractional)
    :m_base(base)
    ,m_fractional(fractional)
    {
        if (m_base < 0 || m_fractional < 0)
        {
            if (m_base > 0)
                m_base = -m_base;
            if (m_fractional > 0)
                m_fractional = -m_fractional;
        }

        reduce();
    }

    FixedPoint2(double n)
    :FixedPoint2(static_cast<std::int16_t>(std::trunc(n)),
        static_cast<std::int8_t>(std::round(n * 100) - std::trunc(n) * 100))
    {

    }

    explicit operator double() const
    {
        return double {m_base + (m_fractional / 100.0)};
    }

    friend bool testDecimal(const FixedPoint2 &fp);

private:
    std::int16_t m_base{};
    std::int8_t m_fractional{};

    void reduce();
};

// reduce the fractional part if it is greater than 99 
// (for both positive and negative FixedPoint2 numbers)
void FixedPoint2::reduce()
{
    m_base += m_fractional / 100; // integer division
    m_fractional = m_fractional % 100;
}


std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
    out << static_cast<double>(fp);
    return out;
}

bool testDecimal(const FixedPoint2 &fp)
{
    if (fp.m_base >= 0)
        return fp.m_fractional >= 0 && fp.m_fractional < 100;
    else
        return fp.m_fractional <= 0 && fp.m_fractional > -100;
}

int main()
{
	FixedPoint2 a{ 0.01 };
	assert(static_cast<double>(a) == 0.01);

	FixedPoint2 b{ -0.01 };
	assert(static_cast<double>(b) == -0.01);

	FixedPoint2 c{ 1.9 }; // make sure we handle single digit decimal
	assert(static_cast<double>(c) == 1.9);

	FixedPoint2 d{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	assert(static_cast<double>(d) == 5.01);

	FixedPoint2 e{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	assert(static_cast<double>(e) == -5.01);

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 f { 106.9978 }; // should be stored with base 107 and decimal 0
	assert(static_cast<double>(f) == 107.0);

	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
	FixedPoint2 g { -106.9978 }; // should be stored with base -107 and decimal 0
	assert(static_cast<double>(g) == -107.0);

	return 0;
}