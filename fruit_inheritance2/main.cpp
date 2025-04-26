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

int main()
{
	Apple a{ "red" };
	Banana b{};

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

	return 0;
}