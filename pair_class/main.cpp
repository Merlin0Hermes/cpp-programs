#include <iostream>

template <typename T>
class Pair1
{
public:
    Pair1(T first, T second)
    :m_first{first}
    ,m_second{second}
    {
    }

    T& first() { return m_first; }
    T& second() { return m_second; }
    const T& first() const { return m_first; }
    const T& second() const { return m_second; }

private:
    T m_first{};
    T m_second{};
};


int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}