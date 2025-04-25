// A fruit class and derived classes

#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
public:
    Fruit(std::string_view name, std::string_view color)
    :m_name{name}
    ,m_color{color}
    {
    }

private:
    std::string m_name{};
    std::string m_color{};
};

class Apple: Fruit
{
public:
    Apple(std::string_view name, std::string_view color, double fiber)
    :Fruit{name, color}
    ,m_fiber{fiber}
    {
    }

private:
    double m_fiber{};
};


int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}