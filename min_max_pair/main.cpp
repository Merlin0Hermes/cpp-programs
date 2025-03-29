#include <algorithm>
#include <cstddef>
#include <vector>
#include <utility>

// returns the index of min and max values in arr as a pair
template <typename T>
std::pair<std::size_t, std::size_t> min_max(const std::vector<T>& arr)
{
    int min{}, max{};
    std::size_t min_index{}, max_index{};
    min = max = arr[0];
    
    for (std::size_t i{0}; i < arr.size(); ++i)
    {
        if (arr[i] > max)
            max_index = i;
        if (arr[i] < min)
            min_index = i;
    }

    return std::pair {min_index, max_index};
}


int main()
{
    
}
