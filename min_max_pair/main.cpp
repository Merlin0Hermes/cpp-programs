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

template <typename T=int>
std::vector<T> get_vector()
{
    std::cout << "Enter numbers to add (use -1 to stop): ";
    std::vector<T> arr{};

    while (true)
    {
        T temp;
        std::cin >> temp;

        if (temp == -1)
            break;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        arr.push_back(temp);
    }

    return arr;
}

int main()
{
    std::vector<int> vector { get_vector() };
    
    if (vector.empty())
        std::cout << "The array has no elements.\n";
    else
        print_min_max(vector, min_max(vector));

}
