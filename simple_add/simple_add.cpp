#include <iostream>

int read_number();
void write_answer(int n);

int main()
{

	return 0;
}


int read_number()
{
	std::cout << "Enter an integer: ";
	
	int num { };
	std::cin >> num;

	return num;
}