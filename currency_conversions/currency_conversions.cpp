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

	switch (currency)
	{
		case 'y':
			cout << amount << " yen is $" << amount * yen_to_dol << '\n';
			break;
		case 'e':
			cout << amount << " euro is $" << amount * euro_to_dol << '\n';
			break;
		case 'p':
			cout << amount << " pound is $" << amount * pnd_to_dol << '\n';
			break;

		default:
			cout << "I don't know this currency!\n";
	}	
	
	return 0;
}