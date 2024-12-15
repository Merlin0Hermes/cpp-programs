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

	string disliked = "brocolli";

	for (string word : words)
	{
		if (word == disliked)
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