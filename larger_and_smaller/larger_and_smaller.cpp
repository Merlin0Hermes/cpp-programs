#include "../std_lib_facilities.h"

int main()
{
	double num;

	cout << "Enter an integer\n";
	double min_val = INFINITY, max_val = -INFINITY;

	while (cin >> num)
	{
		
		if (num < min_val)
		{
			min_val = num;
		}
		if (num > max_val)
		{
			max_val = num;
		}
		
		cout << '\n' << num << '\n';
		if (min_val == num)
			cout << "The smallest so far.\n";
		if (max_val == num)
			cout << "The largest so far.\n";

		
	}
	
	return 0;
}