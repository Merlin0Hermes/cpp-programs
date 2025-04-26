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

    const std::string& name() const { return m_name; }
    const std::string& color() const { return m_color; }

private:
    std::string m_name{};
    std::string m_color{};
};


class Apple: public Fruit
{
public:
    Apple(std::string_view color = "red")
    :Fruit{"apple", color}
    {
    }
};

class Banana: public Fruit
{
public:
    Banana(std::string_view color = "yellow")
    :Fruit{"banana", color}
    {
    }
};


int main()
{
	Apple a{ "red" };
	Banana b{};

	std::cout << "My " << a.name() << " is " << a.color() << ".\n";
	std::cout << "My " << b.name() << " is " << b.color() << ".\n";

	return 0;
}