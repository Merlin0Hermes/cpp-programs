#include <iostream>
#include <string>


template <typename R, typename S, typename T>
class Triad
{
public:
    Triad(const R& x, const S& y, const T& z)
    :m_first{ x }
    ,m_second{ y }
    ,m_third{ z }
    { 
    }

    R first() { return m_first; }
    S second() { return m_second; }
    T third() { return m_third; }



private:
    R m_first{};
    S m_second{};
    T m_third{};

};




int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}