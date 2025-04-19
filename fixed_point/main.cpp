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

    friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2);
    friend std::istream& operator>>(std::istream& in, FixedPoint2& fp);

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

bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    return (fp1.m_base == fp2.m_base) && (fp1.m_fractional == fp2.m_fractional);
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
    double temp{};
    in >> temp;
    FixedPoint2{temp};
    return in;
}


int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}