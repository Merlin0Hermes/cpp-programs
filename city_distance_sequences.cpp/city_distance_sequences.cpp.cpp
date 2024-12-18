// accept distances between cities along a route as values and print total distance, smallest, largest, and mean distance between two cities.

#include "../std_lib_facilities.h"

int main()
{
	
	double dist = 0, total = 0, smallest = INFINITY, largest = -INFINITY, mean;

	cout << "Enter distances between cities\n";

	int i = 0;
	for (vector<double> distances; cin >> dist; distances.push_back(dist))
	{
		total += dist;
		smallest = min(smallest, dist);
		largest = max(largest, dist);
		i++;
	}

	cout << "\nTotal distance: " << total << '\n';
	cout << "Largest distance: " << largest << '\n';
	cout << "Smallest distance: " << smallest << '\n';
	cout << "Mean distance: " << total / i << '\n';


	return 0;
	
}