// program to play rock papers scissors with  user

#include "../std_lib_facilities.h"


int user_points = 0, machine_points = 0;
vector<char> win = { 'r', 'p', 's' };
vector<char> lose = { 's', 'r', 'p' };

void determine_points(char player, char machine);


int main()
{
	vector<int> random_values;

	const int max_turns = 5;

	cout << "Enter " << max_turns << " random numbers.\n";
	cout << "Enter q to exit.\n";

	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		random_values.push_back(temp);
	}

	
	

	string user_choice;
	int i = 0;

	while (true)
	{
		cout << "Enter rock, paper, or scissors: ";
		cin >> user_choice;
		char machine_choice = win[random_values[i] % 3];


		switch (user_choice[0])
		{
			case 'r':
				determine_points('r', machine_choice);
				break;
			case 'p':
				determine_points('p', machine_choice);
				break;
			case 's':
				determine_points('s', machine_choice);
				break;

			default:
				cout << "Invalid choice!\n";
				continue;
		}
		i++;

		if (i == max_turns)
		{
			break;
		}

	}

	cout << "Human points: " << user_points << '\n';
	cout << "Machine points: " << machine_points << '\n';




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