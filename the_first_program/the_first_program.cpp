// program to implement square function using repeated addition and print the square of first hundred numbers using that function. 

#include "../std_lib_facilities.h"

int square(int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += n;
	}
	return result;
}

int main()
{
	

}