#include <iostream>
#include <string>
#include <string_view>

class Ball 
{
private:
    std::string m_color {"black"};
    double m_radius {10.0};

public:
    Ball() = default;

    Ball(std::string_view color)
    :m_color(color)
    {
    
    }

    Ball(double radius)
    :m_radius(radius)
    {
    }

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
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}