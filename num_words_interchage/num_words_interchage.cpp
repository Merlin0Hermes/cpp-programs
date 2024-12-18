// program to display digit form if user enters a word and vice versa 
// example: 7 -> seven and eight -> 8

#include "../std_lib_facilities.h"

int main()
{
	
	const vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const vector<string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	string input;

	cout << "Enter a digit as number or word\n";

	while (cin >> input)
	{
		if (input.size() == 1)
		{
			for (int i = 0; i <= 9; i++)
			{
				if (input == numbers[i])
				{
					cout << words[i] << '\n';
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				if (input == words[i])
				{
					cout << numbers[i] << '\n';
					break;
				}
			}
		}
	}


}