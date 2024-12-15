// program to convert from various currencies to dollars.

#include "../std_lib_facilities.h"

int main()
{
	constexpr double yen_to_dol = 0.0065;
	constexpr double euro_to_dol = 1.05;
	constexpr double pound_to_dol = 1.26;
	constexpr double yuan_to_dol = 0.14;
	constexpr double kroner_to_dol = 0.09;

	char currency;
	cout << "euro: e\n" << "kroner: k\n" << "pound: p\n";
	cout << "yen: y\n" << "yuan: u\n";
	cout << "\nSelect the currency: ";
	
	cin >> currency;

	double amount;
	cout << "Enter the amount of currency: ";
	cin >> amount;

	switch (currency)
	{
		case 'y': case 'Y':
			cout << amount << " yen is $" << amount * yen_to_dol << '\n';
			break;
		case 'e': case 'E':
			cout << amount << " euro is $" << amount * euro_to_dol << '\n';
			break;
		case 'p': case 'P':
			cout << amount << " pound is $" << amount * pound_to_dol << '\n';
			break;
		case 'u': case 'U':
			cout << amount << " yuan is $" << amount * yuan_to_dol << '\n';
			break;
		case 'k': case 'K':
			cout << amount << " kroner is $" << amount * kroner_to_dol << '\n';
			break;

		default:
			cout << "I don't know this currency!\n";
			break;
	}	
	
	return 0;
}