// program to print inputted words like zero, and one, to their digit counterpart.

#include "../std_lib_facilities.h"

int main()
{
	string number;
	int n = -1;

	cout << "Enter the number as word: ";
	cin >> number;

	if (number == "zero")
		n = 0;
	else if (number == "one")
		n = 1;
	else if (number == "two")
		n = 2;
	else if (number == "three")
		n = 3;
	else if (number == "four")
		n = 4;
	else
		simple_error("Not a number I know\n");

	cout << n << '\n';

	return 0;


}