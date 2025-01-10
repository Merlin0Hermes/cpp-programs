// Program to simulate a ball being dropped from a tower.
// Displays the height at each second and when the ball hits the ground

#include <iostream>

double height_at_second(int second)
{
	constexpr double gravity = 9.8;
	double distance = gravity * second * second / 2;
	return distance;
}

int main()
{
	std::cout << "Enter the height of the tower in metres: ";
	double tower_height;
	std::cin >> tower_height;

	double current_height = tower_height;
	int second {};

	while (current_height >= 0)
	{
		std::cout << "At " << second << " seconds, the ball is at height: " << current_height << " metres.\n";
		second++;
		current_height = tower_height - height_at_second(second);
	}

	std::cout << "At " << second << " seconds, the ball is on the ground.\n";


	return 0;
}