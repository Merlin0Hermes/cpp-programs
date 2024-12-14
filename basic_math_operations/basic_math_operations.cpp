#include "../std_lib_facilities.h"

int main()
{
	int val1, val2, smaller, larger;
	cout << "Enter two integers: ";
	cin >> val1 >> val2;

	if (val1 >= val2)
	{
		larger = val1;
		smaller = val2;
	}
	cout << "Smaller: " << smaller << "\n";
	cout << "Larger: " << larger << "\n";

}