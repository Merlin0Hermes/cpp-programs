// program to bleep disliked words from user input

#include "../std_lib_facilities.h"

int main()
{
	vector<string> words;

	cout << "Enter some words: ";
	for (string word; cin >> word; )
	{
		words.push_back(word);
	}

	vector<string> disliked = {"brocolli", "cabbage", "salad"};

	for (string word : words)
	{
		int flag = 0;
		for (string dislike: disliked)
		{
			if (word == dislike)
			{
				flag = 1;
				break;
			}
		}	
		if (flag == 1)
		{
			cout << "BLEEP ";

		}
		else
		{
			cout << word << ' ';
		}
	}
	cout << '\n';
}