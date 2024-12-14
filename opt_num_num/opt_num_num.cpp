// program to perform operations in format opt a b and display result a opt b.

#include "../std_lib_facilities.h"

int main()
{
	string opt;
	double a, b;

	cout << "Enter operation and two numbers: ";
	cin >> opt >> a >> b;

	if (opt == "+" || opt == "plus")
	{
		cout << a << " + " << b << " = " << a + b;
	}
	else if (opt == "-" || opt == "minus")
	{
		cout << a << " - " << b << " = " << a - b;
	}
	else if (opt == "*" || opt == "mul")
	{
		cout << a << "*" << b << " = " << a * b;
	}
	else if (opt == "/" || opt == "div")
	{
		cout << a << "/" << b << " = " << a / b;
	}

	return 0;

}