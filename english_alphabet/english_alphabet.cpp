// program to print the english alphabet using a loop

#include "../std_lib_facilities.h"

int main()
{
	for (int i = 0; i < 26; ++i)
	{
		cout << char('a' + i) << '\t' << int('a' + i) << '\t';
		cout << char('A' + i) << '\t' << int('A' + i) << '\n';
	}
	
	cout << '\n';
	for (int i = 0; i < 9; ++i)
	{
		cout << char('0' + i) << '\t' << int('0' + i) << '\n';
	}

	return 0;
}