
#include <iostream>
#include <vector>

class Point
{
private:
	int m_p1{};
	int m_p2{};

public:
	Point(int p1, int p2)
		: m_p1{ p1 }, m_p2{ p2 }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_p1 << ", " << p.m_p2 << ')';
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
    Point m_p1;
    Point m_p2;
    Point m_p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
    :m_p1{p1}
    ,m_p2{p2}
    ,m_p3{p3}
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return out;
    }
};

class Circle: public Shape
{
private:
    Point m_center;
    int m_radius{};

public:
    Circle(const Point& center, int radius)
    :m_center{center}
    ,m_radius{radius}
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", " << "radius " << m_radius << ")";
        return out;
    }

    int radius() const { return m_radius; }
};

int get_largest_radius(std::vector<Shape*> v)
{
    int max = dynamic_cast<Circle*>(v[0])->radius();
    for (auto* s: v)
    {
        Circle* ptr = dynamic_cast<Circle*>(s); 
        if (ptr)
            max = std::max(dynamic_cast<Circle*>(s)->radius(), max);
    }
    return max;
}


int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

    for (const auto* s: v)
        std::cout << *s << "\n";

	std::cout << "The largest radius is: " << get_largest_radius(v) << '\n'; 

	// delete each element in the vector here
    for (const auto* s: v)
        delete s;

	return 0;
}