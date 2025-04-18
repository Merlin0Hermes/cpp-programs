#include <cassert>
#include <iostream>


class IntArray
{
public:
    IntArray(int length)
    :m_length{ length }
    {
        assert(length > 0);
        m_array = {new int[length]{}};
    }

    ~IntArray()
    {
        delete[] m_array;
    }

private:
    int* m_array{ nullptr };
    int m_length{};
};



IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}