#include <iostream>

template <typename T>
struct Triad
{
    T first { };
    T second { };
    T third { };
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Triad<T>& t)
{
    out << "[" << t.first << ", " << t.second << ", " << t.third << "]";
    return out;
}

template <typename T>
void print(const Triad<T>& triad)
{
    std::cout << triad;
}

int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

    std::cout << "\n";

	return 0;
}