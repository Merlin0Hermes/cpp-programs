// A class to store x, y, and z coordinates


#include <iostream>


class Point3d
{
public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() const
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }

private:
    int m_x {};
    int m_y {};
    int m_z {};
    
};



int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}