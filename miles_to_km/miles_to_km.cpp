#include "../std_lib_facilities.h"

#define mi_to_km_const 1.609

int main()
{
	double miles;
	cout << "Enter the distance in miles: ";
	cin >> miles;

	cout << miles << " miles is " << miles * mi_to_km_const << " kilometres.\n";
	return 0;
}