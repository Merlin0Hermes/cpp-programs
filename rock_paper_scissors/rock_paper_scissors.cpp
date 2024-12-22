// program to play rock papers scissors with  user

#include "../std_lib_facilities.h"


int user_points = 0, machine_points = 0;


void determine_points(char player, char machine);


int main()
{
	vector<int> random_values;

	vector<string> choices = { "rock", "paper", "scissors" };

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


	for (int i = 0; i < max_turns; i++)
	{
		cout << "\nEnter rock, paper, or scissors: ";
		cin >> user_choice;
		string machine_choice = choices[random_values[i] % 3];


		switch (user_choice[0])
		{
			case 'r':
				determine_points('r', machine_choice[0]);
				break;
			case 'p':
				determine_points('p', machine_choice[0]);
				break;
			case 's':
				determine_points('s', machine_choice[0]);
				break;

			default:
				cout << "Invalid choice!\n";
				continue;
		}

		cout << "Machine chose: " << machine_choice << '\n';

	}


	cout << "\nHuman points: " << user_points << '\n';
	cout << "Machine points: " << machine_points << '\n';

	if (user_points > machine_points)
	{
		cout << "\nHuman wins!!\n";
	}
	else if (machine_points > user_points)
	{
		cout << "\nMachine wins!!\n";
	}
	else
	{
		cout << "\nIt is a draw!!\n";
	}



	return 0;
}


void determine_points(char player, char machine)
{

	vector<char> win = { 'r', 'p', 's' };
	vector<char> lose = { 's', 'r', 'p' };

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