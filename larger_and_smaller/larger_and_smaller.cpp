#include "../std_lib_facilities.h"

int main()
{
	double num1, num2;

	cout << "Enter two integers: ";
	while (cin >> num1 >> num2)
	{
		if (num1 == num2)
		{
			cout << "The numbers are equal.\n";
		}
		else
		{
			cout << "The smaller value is: " << min(num1, num2) << '\n';
			cout << "The larger value is: " << max(num1, num2) << '\n';

			if (max(num1, num2) - min(num1, num2) < 1.0 / 100)
			{
				cout << "The numbers are almost equal.\n";
			}
		}

	}
	
	return 0;
}