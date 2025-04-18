#include <iostream>
#include <cassert>
#include <cstdint>


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
	FixedPoint2 a{ 1, 104 };
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 2.04);
	assert(testDecimal(a));

	FixedPoint2 b{ 1, -104 };
	assert(static_cast<double>(b) == -2.04);
	assert(testDecimal(b));

	FixedPoint2 c{ -1, 104 };
	assert(static_cast<double>(c) == -2.04);
	assert(testDecimal(c));

	FixedPoint2 d{ -1, -104 };
	assert(static_cast<double>(d) == -2.04);
	assert(testDecimal(d));

	return 0;
}