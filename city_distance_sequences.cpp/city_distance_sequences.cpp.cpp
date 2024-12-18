// accept distances between cities along a route as values and print total distance, smallest, largest, and mean distance between two cities.

#include "../std_lib_facilities.h"

int main()
{
	vector<int> distances;
	int dist = 0, total = 0;

	cout << "Enter distances between cities\n";
	for (; cin >> dist; distances.push_back(dist))
	{
		total += dist;
		
	}

	cout << "Total distance: " << total << '\n';


	return 0;
	
}