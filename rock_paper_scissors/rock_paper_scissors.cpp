// program to play rock papers scissors with  user

#include "../std_lib_facilities.h"


int user_points = 0, machine_points = 0;
vector<char> win = { 'r', 'p', 's' };
vector<char> lose = { 's', 'r', 'p' };


int main()
{
	vector<double> random_values;

	cout << "Enter 5 random numbers.";
	cout << "Enter q to exit.\n";
	for (double temp; cin >> temp; )
	{
		random_values.push_back(temp);
	}
	

	string object;
	while (true)
	{
		cout << "Enter rock, paper, or scissors: ";
		cin >> object;

		switch (object[0])
		{
			case 'r':




		}

	}




	

	return 0;
}

void determine_points(char player, char machine)
{
	for (int i = 0; i < 3; i++)
	{
		if (player == win[i] and machine == lose[i])
		{
			user_points++;
			break;
		}
		if (machine == win[i] and player == lose[i])
		{
			machine_points++;
			break;
		}
	}
}