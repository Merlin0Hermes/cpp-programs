
#include <iostream>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};


class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
    {
        return shape.print(out);
    }

    virtual ~Shape() = default;
};


class Triangle: public Shape
{
private:
    Point m_x;
    Point m_y;
    Point m_z;

public:
    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_x << ", " << m_y << ", " << m_z << ")";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Triangle& t)
    {
        return t.print(out);
    }
};

class Circle: public Shape
{
private:
    Point m_center;
    int m_radius{};

public:
    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", " << "radius " << m_radius << ")";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Circle& c)
    {
        return c.print(out);
    }
};


int main()
{
    Circle c{ Point{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    std::cout << t << '\n';

    return 0;
}