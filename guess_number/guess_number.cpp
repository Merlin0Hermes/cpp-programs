// program to guess which number user typed in

#include "../std_lib_facilities.h"

int main()
{
	int low = 1, high = 100;
	char answer;

	cout << "Think of a number between 1 and 100: ";
	cout << "\nEnter y or n\n";

	int guess;
	while (low <= high)
	{
		guess = (low + high) / 2;

		cout << "Is you number less than " << guess << "? ";
		cin >> answer;

		if (answer == 'y')
		{
			high = guess - 1;
		}
		else if (answer == 'n')
		{
			cout << "Is your number " << guess << "? ";
			cin >> answer;
			
			if (answer == 'y')
			{
				cout << "Great! I guessed you number :)\n";
				return 0;
			}
			else if (answer == 'n')
			{
				low = guess + 1;
			}
		}
	}

	cout << "The number you have chosen is not between 1 and 100";

}