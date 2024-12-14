// program to accept and display different coins like pennies, nickels, etc and calculate the total

#include "../std_lib_facilities.h"

int main()
{
	int pennies, nickels, dimes, quarters, half_dollars, one_dollars;

	cout << "How many pennies do you have? ";
	cin >> pennies;

	cout << "How many nickels do you have? ";
	cin >> nickels;

	cout << "How many dimes do you have? ";
	cin >> dimes;

	cout <<  "How many quarters do you have? ";
	cin >> quarters;

	cout << "How many half-dollars do you have? ";
	cin >> half_dollars;

	cout << "How many one-dollars do you have? ";
	cin >> one_dollars;

	cout << "\nYou have " << pennies << ((pennies == 1) ? " penny." : " pennies.") << "\n";
	cout << "You have " << nickels << ((nickels == 1) ? " nickel." : " nickels.") << "\n";
	cout << "You have " << dimes << ((dimes == 1) ? " dime." : " dimes.") << "\n";
	cout << "You have " << quarters << ((quarters == 1) ? " quarter." : " quarters.") << "\n";
	cout << "You have " << half_dollars << ((half_dollars == 1) ? " half-dollar." : " half-dollars.") << "\n";
	cout << "You have " << one_dollars << ((one_dollars == 1) ? " one-dollar." : " one-dollars.") << "\n";

	cout << "The value of all you coins is $"
		<< (one_dollars * 100 + half_dollars * 50 + quarters * 25 + dimes * 10 + nickels * 5 + pennies) / 100.0
		<< "\n";

	return 0;


}