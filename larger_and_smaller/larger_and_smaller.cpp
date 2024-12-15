#include "../std_lib_facilities.h"

int main()
{
	constexpr double in_to_m = 0.0254;
	constexpr double ft_to_m = 0.3048;
	constexpr double cm_to_m = 0.01;
	double num;

	cout << "Enter an number with unit (cm, m, in, ft)\n";

	int n = 0;
	double min_val = INFINITY, max_val = -INFINITY, sum = 0;
	string unit = "";

	while (cin >> num >> unit)
	{	
		double true_val = 0.0;
		if (unit == "cm")
		{
			true_val = num * cm_to_m;
		}
		else if (unit == "in")
		{
			true_val = num * in_to_m;
		}
		else if (unit == "ft")
		{
			true_val = num * ft_to_m;
		}
		else if (unit == "m")
		{
			true_val = num;
		}
		else
		{
			cout << "Unknown unit!\n";
			continue;
		}

		max_val = max(true_val, max_val);
		min_val = min(true_val, min_val);
		
		cout << '\n' << num << unit << '\n';
		if (min_val == true_val)
			cout << "The smallest so far.\n";
		if (max_val == true_val)
			cout << "The largest so far.\n";

		n++;
		sum += true_val;
	}

	cout << "\nLargest value: " << max_val << '\n';
	cout << "Smallest value: " << min_val << '\n';
	cout << "Number of values: " << n << '\n';
	cout << "Sum of values: " << sum << 'm' << '\n';

	
	return 0;
}