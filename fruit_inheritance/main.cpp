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

    std::string_view name() const { return m_name; }
    std::string_view color() const { return m_color; }

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

    friend std::ostream& operator<<(std::ostream& out, const Apple& a)
    {
        out << "Apple(" << a.name() << ", " << a.color() << ", " << a.m_fiber << ")";
        return out;
    }

private:
    double m_fiber{};
};


class Banana: Fruit
{
public:
    Banana(std::string_view name, std::string_view color)
    :Fruit{name, color}
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Banana& a)
    {
        out << "Banana(" << a.name() << ", " << a.color() << ")";
        return out;
    }
};


int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}