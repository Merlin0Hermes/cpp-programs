#include <iostream>
#include <cmath>


class Point2d
{

    
public: 
    Point2d() = default;

    Point2d(double x, double y)
    :m_x { x }
    ,m_y { y }
    {
    }

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }


    double distanceTo(const Point2d& other) const
    {
        double x1 = m_x, y1 = m_y;
        double x2 = other.m_x, y2 = other.m_y;

        return std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    }

private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };

};

#include <cmath>
#include <iostream>

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}