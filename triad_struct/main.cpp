#include <iostream>

template <typename T>
struct Triad
{
    T x { };
    T y { };
    T z { };
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Triad<T>& triad)
{
    out << "[" << triad.x << ", " << triad.y << ", " << triad.z << "]";
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