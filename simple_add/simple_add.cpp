#include <iostream>

int main()
{
	std::cout << "Adds two numbers.\n";

	int a{ read_number() };
	int b{ read_number() };

	write_answer(a + b);

	return 0;
}
