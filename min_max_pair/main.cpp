#include <cstddef>
#include <vector>
#include <utility>
#include <iostream>
#include <limits>


// returns the index of min and max values in arr as a pair
template <typename T>
std::pair<std::size_t, std::size_t> min_max(const std::vector<T>& arr)
{
    std::size_t min_index{0}, max_index{0};
    
    for (std::size_t i{0}; i < arr.size(); ++i)
    {
        if (arr[i] > arr[max_index])
            max_index = i;
    
        if (arr[i] < arr[min_index])
            min_index = i;
        
    }

    return std::pair {min_index, max_index};
}


template <typename T>
void print_vector(const std::vector<T>& arr)
{
    std::cout << "With array ( ";

    bool comma { false };
    for (const auto& a: arr)
    {
        if (comma)
            std::cout << ", ";

        std::cout << a;
        comma = true;
    }
    std::cout << " ):\n";

}

template <typename T>
void print_min_max(const std::vector<T>& arr, std::pair<std::size_t, std::size_t> pair)
{
    print_vector(arr);

    std::cout << "The min element has index " << pair.first << " and value " << arr[pair.first] << "\n";
    std::cout << "The max element has index " << pair.second << " and value " << arr[pair.second] << "\n";

}

template <typename T>
std::vector<T> get_vector()
{
    std::cout << "Enter numbers to add (use -1 to stop): ";
    std::vector<T> arr{};

    while (true)
    {
        T temp;
        std::cin >> temp;

        if (temp == -1)
        {
            if (!arr.empty())
                break;
            else
                std::cout << "Enter atleast one element.\n";
            continue;              
        }


        arr.push_back(temp);

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
}

int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    print_min_max(v1, min_max(v1));
    std::cout << "\n";
    print_min_max(v2, min_max(v2));


}
