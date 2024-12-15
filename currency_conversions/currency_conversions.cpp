// program to convert from various currencies to dollars.

#include "../std_lib_facilities.h"

int main()
{
	constexpr double yen_to_dol = 0.0065;
	constexpr double euro_to_dol = 1.05;
	constexpr double pnd_to_dol = 1.26;

	char currency;
	cout << "Enter if yen, euro, or pound (y, e, p): ";
	cin >> currency;

	double amount;
	cout << "Enter the amount of currency: ";
	cin >> amount;

	if (currency == 'y')
	{
		cout << amount << " yen is $" << amount * yen_to_dol << '\n';
	}
	else if (currency == 'e')
	{
		cout << amount << " euro is $" << amount * euro_to_dol << '\n';
	}
	else if (currency == 'p')
	{
		cout << amount << " pound is $" << amount * pnd_to_dol << '\n';
	}
	else
	{
		cout << "I don't know this currency!\n";
	}
}