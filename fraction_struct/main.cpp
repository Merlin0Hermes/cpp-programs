// prompts the user for two fractions and multiplies them and prints the result

#include <iostream>

struct Fraction
{
    int numerator{ };
    int denominator{ };
};

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    std::cout << "Enter a value for the numerator: ";
    in >> fraction.numerator;

    std::cout << "Enter a value for the denominator: ";
    in >> fraction.denominator;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

Fraction get_fraction()
{
    Fraction fraction;
    std::cin >> fraction;
    return fraction;
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction result { f1.numerator + f2.numerator, f1.denominator + f2.denominator };
    return result;
}

int main()
{
    Fraction fraction { get_fraction() };
}

