// program to display if a number is odd or even

#include "../std_lib_facilities.h"

int main()
{
	int num;

	cout << "Enter a number: ";
	cin >> num;

	if (num % 2 == 0)
		cout << "The value " << num << " is an even number.\n";
	else
		cout << "The value " << num << " is an odd number.\n";

	return 0;
}