// accept distances between cities along a route as values and print total distance, smallest, largest, and mean distance between two cities.

#include "../std_lib_facilities.h"

int main()
{
	vector<double> distances;
	double dist = 0, total = 0, smallest = INFINITY, largest = -INFINITY, mean;

	cout << "Enter distances between cities\n";
	for (; cin >> dist; distances.push_back(dist))
	{
		total += dist;
		smallest = min(smallest, dist);
		largest = max(largest, dist);
	}

	cout << "Total distance: " << total << '\n';
	cout << "Largest distance: " << largest << '\n';
	cout << "Smallest distance: " << smallest << '\n'


	return 0;
	
}