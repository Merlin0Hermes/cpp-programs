#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <utility>


class IntArray
{
public:
    IntArray(int length)
    :m_length{ length }
    {
        assert(length > 0);
        m_array = {new int[length]};
    }

    IntArray(const IntArray& source)
    {
        if (this == &source)
            return;

        delete[] m_array;
        
        assert(source.m_length > 0);

        m_length = source.m_length;
        m_array = {new int[m_length]};

        for (std::size_t i {0}; i < static_cast<std::size_t>(m_length); ++i)
            m_array[i] = source.m_array[i];
    }

    ~IntArray()
    {
        delete[] m_array;
        m_array = nullptr;
    }

    const int& operator[](int index) const;
    int& operator[](int index);
    IntArray& operator=(const IntArray& source);

    friend std::ostream& operator<<(std::ostream& out, IntArray arr);

private:
    int* m_array{ nullptr };
    int m_length{};


};


std::ostream& operator<<(std::ostream& out, IntArray arr)
{
    for (int i {0}; i < arr.m_length; ++i)
    {
        out << arr[i];
        if (i < (arr.m_length - 1))
            out << " ";
    }
    return out;
}


const int& IntArray::operator[](int index) const
{
    assert(index >= 0);
    assert(index < m_length && "Index out of bounds");

    return m_array[index];
}

int& IntArray::operator[](int index)
{
    return const_cast<int&>(std::as_const(*this)[index]);
}


IntArray& IntArray::operator=(const IntArray& source)
{
    if (this == &source)
        return *this;
    assert(source.m_length > 0);

    delete[] m_array;

    m_length = source.m_length;
    m_array = {new int[m_length]};

    for (int i {0}; i < m_length; ++i)
        m_array[i] = source.m_array[i];
    return *this;
}


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