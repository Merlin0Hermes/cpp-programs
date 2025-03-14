// program to practice find and remove errors
#include <iostream>


int main()
{
	using namespace std;
	try
	{
		cout << "Success!\n";
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