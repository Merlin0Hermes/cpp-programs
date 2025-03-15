// A struct that stores 
// 1. How many ads were watched.
// 2. What percentage of users clicked on an ad.
// 3. The average earnings per clicked ad.
// and prints the information

#include <iostream>

struct AdRevenue 
{
    int ads_watched { }; // number of ads watched by users
    double percent_clicked { }; // % of users that clicked on ads 
    double average_earnings { }; // average earnings per ad
};

AdRevenue generate_struct()
{
    AdRevenue ar;

    std::cout << "Enter the number of ads watched: ";
    std::cin >> ar.ads_watched;

    double temp;
    std::cout << "Enter the percentage of users that clicked on ads: ";
    std::cin >> temp;
    ar.percent_clicked = temp / 100.0;

    std::cout << "Enter the average earnings per ad: ";
    std::cin >> ar.average_earnings;

    return ar;
}

int main()
{

    return 0;
}