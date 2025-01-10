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
	return 0;
}