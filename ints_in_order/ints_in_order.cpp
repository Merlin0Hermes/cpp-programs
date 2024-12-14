// program to accept 3 integers and print them in numerical order

#include "../std_lib_facilities.h"

int main()
{
	int a, b, c;

	cout << "Enter three integers: ";
	cin >> a >> b >> c;

	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);


	cout << a << ' ' << b << ' ' << c;

	return 0;

}