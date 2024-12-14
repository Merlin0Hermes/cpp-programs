#include "../std_lib_facilities.h"

int main()
{
	string first_name, friend_name;
	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;
	
	cout << "Enter the name of the other friend: ";
	cin >> friend_name;

	cout << "Dear " << first_name << "," << "\n";
	cout << "\tHow are you? I am fine. I miss you.\n";
	cout << "Have you seen " << friend_name << " lately?\n";
	
}