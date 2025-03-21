#include <iostream>

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
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> denominator;
    }

    Fraction multiply(Fraction other)
    {
        return Fraction{numerator * other.numerator, denominator * other.denominator };
    }

    void print()
    {
        std::cout << numerator << "/" << denominator << "\n";
    }


};



int main()
{
    Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print();

    return 0;
}