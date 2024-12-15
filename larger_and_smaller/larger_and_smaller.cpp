#include "../std_lib_facilities.h"

int main()
{
	double num;

	cout << "Enter an number with unit (cm, m, in, ft)\n";
	double min_val = INFINITY, max_val = -INFINITY, true_val = 0;
	string unit = "";

	while (cin >> num >> unit)
	{
		if (unit == "cm")
		{
			true_val = num / 100;
		}
		else if (unit == "in")
		{
			true_val = (num * 2.54) / 100;
		}
		else if (unit == "ft")
		{
			true_val = num * 12 * 2.54 / 100;
		}
		else
		{
			true_val = num;
		}

		if (true_val < min_val)
		{
			min_val = true_val;
		}
		if (true_val > max_val)
		{
			max_val = true_val;
		}
		
		cout << '\n' << num << unit << '\n';
		if (min_val == true_val)
			cout << "The smallest so far.\n";
		if (max_val == true_val)
			cout << "The largest so far.\n";

		
	}
	
	return 0;
}