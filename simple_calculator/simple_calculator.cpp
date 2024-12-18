// simple calculator program

#include "../std_lib_facilities.h"

int main()
{
	char opt;
	double num1, num2;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

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