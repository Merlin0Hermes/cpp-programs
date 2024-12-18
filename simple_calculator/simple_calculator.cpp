// simple calculator program

#include "../std_lib_facilities.h"

const vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const vector <string> numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

int number_convert(string s);


int main()
{

	char opt;
	double num1, num2;
	string number1, number2;


	while (true)
	{
		cout << "Enter two digits (0 - 9) or (zero to nine)\n";
		cin >> number1 >> number2;
		
		num1 = number_convert(number1);
		num2 = number_convert(number2);

		if (num1 == -1 || num2 == -1)
		{
			cout << "Invalid number.\n";
			return 1;
		}


		cout << "Enter the operaton (+, -, *, / )\n";
		cout << "Enter 0 to exit.\n";
		cin >> opt;

		switch (opt)
		{
			case '+':
				cout << "Sum of " << num1 << " and " << num2 << " is " << num1 + num2 << '\n';
				break;
			case '-':
				cout << "Subtracting " << num1 << " from " << num2 << " is " << num1 - num2 << '\n';
				break;
			case '*':
				cout << "Product of " << num1 << " and " << num2 << " is " << num1 * num2 << '\n';
				break;
			case '/':
				if (num2 == 0)
				{
					cout << "Division by zero not possible.\n";
					return 1;
				}
				cout << "Division of " << num1 << " by " << num2 << " is " << num1 / num2 << '\n';
				break;
			case '0':
				return 0;
			default:
				cout << "Invalid Operation.\n";
				break;
		}
		
	}

	return 0;

}


int number_convert(string s)
{
	if (s.size() == 1)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (s == numbers[i])
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (s == words[i])
			{
				return i;
			}
		}
	}

	return -1;
	
}