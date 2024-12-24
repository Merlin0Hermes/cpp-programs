// program to practice find and remove errors

#include "../std_lib_facilities.h"


int main()
{
	try
	{
		                                          // logical error here? 
		vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
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