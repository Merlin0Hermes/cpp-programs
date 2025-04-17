#include <iostream>
#include <numeric>

class Fraction
{
private:
    int numerator{ 0 };
    int denominator{ 1 };

public:
    explicit Fraction(int x=0, int y=1)
    :numerator { x }
    ,denominator { y }
    {
        reduce();
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> denominator;
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int n);
    friend Fraction operator*(int n, const Fraction& f);

    void print()
    {
        std::cout << numerator << "/" << denominator << "\n";
    }

    void reduce()
    {
        int gcd { std::gcd(numerator, denominator) };
        if (gcd)
        {
            numerator /= gcd;
            denominator /= gcd;            
        }
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction {f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

Fraction operator*(const Fraction& f, int n)
{  
    return Fraction {f.numerator * n, f.denominator};
}

Fraction operator*(int n, const Fraction& f)
{
    return Fraction { f * n };
}


int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}