// program to add two numbers using functions and header files

#include "io.h"

int main()
{

	int a{ read_number() };
	int b{ read_number() };

	write_answer(a + b);

	return 0;
}
