#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter some numbers\n";

	vector<double> numbers;
	for (double d; cin >> d; )
	{
		numbers.push_back(d);
	}

	sort(numbers);

	double median;
	int n = numbers.size();

	if (n >= 2 && n % 2 == 0)
	{
		double sum = numbers[n / 2] + numbers[n / 2 - 1];
		median = sum / 2;
	}
	else if (n >= 1 && n % 2 != 0)
	{
		median = numbers[n / 2];
	}
	else
	{
		simple_error("Invalid data!\n");
	}

	cout << "Median is " << median << "\n";

	return 0;

}