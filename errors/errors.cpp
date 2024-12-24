// program to practice find and remove errors

#include "../std_lib_facilities.h"


int main()
{
	try
	{
		string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}