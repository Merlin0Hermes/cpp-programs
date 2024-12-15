#include "../std_lib_facilities.h"

int main()
{
	int num1, num2;

	cout << "Enter two integers: ";
	while (cin >> num1 >> num2)
	{
		cout << "the smaller value is: " << min(num1, num2) << '\n';
		cout << "the larger value is: " << max(num1, num2) << '\n';
	}
	
	return 0;
}