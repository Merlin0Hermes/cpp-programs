#include <iostream>
#include <array>
#include <string_view>

struct Item
{
    std::string_view name {};
    int gold {};
};

int main()
{
    std::array items {
        Item{"sword", 5},              
        Item{"dagger", 3},
        Item{"club", 2},
        Item{"spear", 7}
    };

    
    return 0;
}