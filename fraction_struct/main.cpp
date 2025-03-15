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

Fraction get_fraction()
{

}

