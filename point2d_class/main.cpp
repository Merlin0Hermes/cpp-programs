#include <iostream>


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

private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };

};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    return 0;
}