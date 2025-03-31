#include <ios>
#include <string>
#include <string_view>
#include <array>
#include <iostream>

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

        max_animals
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

    static_assert(animals.size() == max_animals);


}

std::istream& operator>>(std::istream& in, Animal::Type& t)
{
    std::string name{};
    in >> name;

    for (std::size_t i{0}; i < Animal::animals.size(); ++i)
    {
        if (name == Animal::animals[i].name)
        {
            t = static_cast<Animal::Type>(i);
            return in;
        }
    }

   
    in.setstate(std::ios_base::failbit);
    return in;
    
}

std::ostream& operator<<(std::ostream& out, Animal::Type t)
{
    return out << Animal::animals[static_cast<std::size_t>(t)].name;
}

std::ostream& operator<<(std::ostream& out, Animal::Data a)
{
    return out << "A " << a.name << " has " << a.num_legs << " legs and says " << a.sound << ".\n";
}

bool operator==(const Animal::Data& a, const Animal::Data& b)
{
    if (a.name == b.name && a.num_legs == b.num_legs && a.sound == b.sound)
        return true;
    return false;
}

void print_animals(Animal::Type type, bool failed=false)
{
    if (!failed) // print the animal user inputted
        std::cout << Animal::animals[static_cast<std::size_t>(type)]; 

    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (const auto& a: Animal::animals)
    {
        if (!failed && a == Animal::animals[static_cast<std::size_t>(type)])
            continue; // skip the user inputted animal
        std::cout << a;
    }
}

int main()
{
    std::cout << "Enter an animal: ";
    Animal::Type type{};
    
    std::cin >> type;

    if (!std::cin)
        std::cout << "That animal couldn't be found.\n";
    print_animals(type, !static_cast<bool>(std::cin));

}