#include "../std_lib_facilities.h"

int main()
{
	double val1, val2, smaller, larger;
	cout << "Enter two floating point values: ";
	cin >> val1 >> val2;

	if (val1 >= val2)
	{
		larger = val1;
		smaller = val2;
	}
	cout << "Smaller: " << smaller << "\n";
	cout << "Larger: " << larger << "\n";
	cout << "Sum: " << val1 + val2 << "\n";
	cout << "Difference: " << val1 - val2 << "\n";
	cout << "Product: " << val1 * val2 << "\n";
	cout << "Ratio: " << val1 / val2 << "\n";

}