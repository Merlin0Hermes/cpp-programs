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
        numerator /= gcd;
        denominator /= gcd;
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
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}