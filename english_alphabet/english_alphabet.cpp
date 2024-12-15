// program to print the english alphabet using a loop

#include "../std_lib_facilities.h"

int main()
{
	int i = 0;
	while (i <= 26)
	{
		cout << char('a' + 1) << '\t' << int('a' + 1) << '\n';
	}

	return 0;
}