// program to display string in order

#include "../std_lib_facilities.h"

int main()
{
	string s1, s2, s3;
	cout << "Enter 3 words: ";
	cin >> s1 >> s2 >> s3;

	if (s1 > s2)
		swap(s1, s2);
	if (s1 > s3)
		swap(s1, s3);
	if (s2 > s3)
		swap(s2, s3);

	cout << s1 << ' ' << s2 << ' ' << s3 << '\n';

	return 0;
}