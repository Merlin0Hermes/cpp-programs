#include <string_view>
#include <array>

namespace Animal
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
    };

    struct Data
    {
        std::string_view name{};
        int num_legs {};
        std::string_view sound{};
    };

    constexpr std::array animals {
            Data{"chicken", 2, "cluck"},
            Data{"dog", 4, "woof"},
            Data{"cat", 4, "meow"},
            Data{"elephant", 4, "pawoo"},
            Data{"duck", 2, "quack"},
            Data{"snake", 0, "hissss"}
    };
    

}