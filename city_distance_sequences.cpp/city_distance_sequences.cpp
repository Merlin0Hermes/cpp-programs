// accept distances between cities along a route as values and print total distance, smallest, largest, and mean distance between two cities.

#include "../std_lib_facilities.h"

int main()
{

	vector<double> distances;
	double dist = 0, total = 0, smallest = INFINITY, largest = -INFINITY, mean;

	cout << "Enter distances between cities\n";

	int size = 0;
	while (cin >> dist)
	{
		distances.push_back(dist);
		size++;
	}

	
	for (double x: distances)
	{
		total += x;
		smallest = min(smallest, x);
		largest = max(largest, x);
	}

	cout << "\nTotal distance: " << total << '\n';
	cout << "Largest distance: " << largest << '\n';
	cout << "Smallest distance: " << smallest << '\n';
	cout << "Mean distance: " << total / size << '\n';

	return 0;
	
}