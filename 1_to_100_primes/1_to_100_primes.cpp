// program to print all primes from 1 to 100

#include "..\std_lib_facilities.h"

bool is_prime(int n);

int main()
{
	const int start = 1, end = 100;
	vector<int> primes;

	for (int i = start; i <= end; i++)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
	}

	cout << '\n';
	for (int x : primes)
	{
		cout << x << '\n';
	}

	return 0;
}

bool is_prime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	else if (n != 2 && n % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}