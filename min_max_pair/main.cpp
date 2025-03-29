#include <cstddef>
#include <vector>
#include <utility>
#include <iostream>


// returns the index of min and max values in arr as a pair
template <typename T>
std::pair<std::size_t, std::size_t> min_max(const std::vector<T>& arr)
{
    T min{}, max{};
    std::size_t min_index{0}, max_index{0};
    min = max = arr[0];
    
    for (std::size_t i{0}; i < arr.size(); ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }

    return std::pair {min_index, max_index};
}


template <typename T>
void print_vector(const std::vector<T>& arr)
{
    std::cout << "With array ( ";

    std::size_t len {arr.size()};
    for (std::size_t i{0}; i < len; ++i)
    {
        std::cout << arr[i];
        if (i < len - 1)
            std::cout << ", ";
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

int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    print_min_max(v1, min_max(v1));
    std::cout << "\n";
    print_min_max(v2, min_max(v2));


}
