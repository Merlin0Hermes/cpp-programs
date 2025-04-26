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
protected:
    Apple(std::string_view name, std::string_view color)
    :Fruit{name, color}
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

class GrannySmith: public Apple
{
public:
    GrannySmith(std::string_view color = "green")
    :Apple{"granny smith apple", color}
    {
    }
};


int main()
{
	Apple a{ "red" };
	Banana b{};
    GrannySmith c;

	std::cout << "My " << a.name() << " is " << a.color() << ".\n";
	std::cout << "My " << b.name() << " is " << b.color() << ".\n";
    std::cout << "My " << c.name() << " is " << c.color() << ".\n";

	return 0;
}