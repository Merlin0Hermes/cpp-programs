#include <iostream>
#include <string>
#include <string_view>

class Ball 
{
private:
    std::string m_color {"blue"};
    double m_radius {};

public:
    Ball(std::string_view color, double radius)
    :m_color { color }
    ,m_radius { radius }
    {  
    }

    std::string_view color() const { return m_color; }
    double radius() const { return m_radius; }

};

void print(const Ball& ball)
{
    std::cout << "Ball(" << ball.color() << ", " << ball.radius() << ")\n";
}



int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}