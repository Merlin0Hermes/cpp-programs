// program to print the english alphabet using a loop

#include "../std_lib_facilities.h"

int main()
{
	for (int i = 0; i < 26; ++i)
	{
		cout << char('a' + i) << '\t' << int('a' + i) << '\n';
	}

	return 0;
}