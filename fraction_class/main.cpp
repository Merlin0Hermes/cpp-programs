#include <iostream>
#include <numeric>
#include <exception>
#include <stdexcept>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    explicit Fraction(int numerator=0, int denominator=1)
    :m_numerator { numerator }
    ,m_denominator { denominator }
    {
        if (denominator == 0)
            throw std::runtime_error{"Invalid denominator"};
        reduce();
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int n);
    friend Fraction operator*(int n, const Fraction& f);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);

    void print()
    {
        std::cout << m_numerator << "/" << m_denominator << "\n";
    }

    void reduce()
    {
        int gcd { std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;            
        }
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f, int n)
{  
    return Fraction {f.m_numerator * n, f.m_denominator};
}

Fraction operator*(int n, const Fraction& f)
{
    return Fraction { f * n };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    return (out << f.m_numerator << "/" << f.m_denominator);
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    int n{}, d{};
    char discard{};
    in >> n >> discard >> d;

    if (d == 0 || discard != '/')
        std::cin.setstate(std::ios_base::failbit);

    if (std::cin)
        f = Fraction {n, d};
    return in;
}   


bool operator==(const Fraction& f1, const Fraction& f2)
{
    return (f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2)
{
    if (f1.m_denominator == f2.m_denominator)
        return f1.m_numerator < f2.m_numerator;

    return (f1.m_numerator * f2.m_denominator) < (f2.m_numerator * f1.m_denominator);
}

bool operator>(const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 > f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}



int main()
{
    std::cout << "Enter the numerator: ";
    int num{};
    std::cin >> num;

    std::cout << "Enter the denominator: ";
    int denom{};
    std::cin >> denom;

    try
    {
        Fraction fraction {num, denom};
        std::cout << fraction << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}