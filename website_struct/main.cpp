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

    std::cout << "Enter the percentage of users that clicked on ads: ";
    std::cin >> ar.percent_clicked;

    std::cout << "Enter the average earnings per ad (in $): ";
    std::cin >> ar.average_earnings;

    return ar;
}

std::ostream& operator<<(std::ostream& out, AdRevenue ar)
{
    out << "Number of ads watched: " << ar.ads_watched << "\n";
    out << "Percentage of users that clicked on ads: " << ar.percent_clicked << "%\n";
    out << "Average earnings per ad $: " << ar.average_earnings << "\n";

    return out;
}


void print_values(AdRevenue ar) // also prints total earnings by multiplying everything
{
    std::cout << "\n" << ar << "\n";
    double total_earnings { ar.ads_watched * (ar.percent_clicked / 100) * ar.average_earnings };
    std::cout << "Total earnings for the day: $" << total_earnings << "\n";
}


int main()
{
    AdRevenue ad_revenue { generate_struct() };
    print_values(ad_revenue);
    return 0;
}