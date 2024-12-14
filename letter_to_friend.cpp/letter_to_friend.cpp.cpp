#include "../std_lib_facilities.h"

int main()
{
	string first_name, friend_name;
	int age;
	cout << "Enter the name and age of the person you want to write to: ";
	cin >> first_name >> age;

	if (age <= 0 || age >= 110)
		simple_error("you're kidding!\n");
	
	cout << "Enter the name of the other friend: ";
	cin >> friend_name;

	char friend_sex = 0;
	cout << "Enter m if friend is male or f if friend is female\n";
	cin >> friend_sex;

	cout << "\nDear " << first_name << "," << "\n";
	cout << "\tHow are you? I am fine. I miss you.\n";
	cout << "Have you seen " << friend_name << " lately?\n";
	
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";

	cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age > 70)
		cout << "I hope you are enjoying retirement.\n";	

	cout << "Yours sincerely\n\n\n";
	cout << "Jack the Ripper.\n";

	return 0;
}