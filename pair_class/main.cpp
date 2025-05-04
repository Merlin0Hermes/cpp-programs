#include <iostream>
#include <string>
#include <string_view>

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


template <typename T, typename U>
class Pair
{
public:
    Pair(T x, U y)
    :m_x{x}
    ,m_y{y}
    {
    }

    T& first() { return m_x; }
    U& second() { return m_y; }

    const T& first() const { return m_x; }
    const U& second() const { return m_y; }


private:
    T m_x{};
    U m_y{};
};


template <typename T>
class StringValuePair: public Pair<std::string, T>
{
public:
    StringValuePair(std::string_view str, const T& value)
    :Pair<std::string, T>{static_cast<std::string>(str), value}
    {
    }
};


int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}