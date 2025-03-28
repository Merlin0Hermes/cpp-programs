#include <iostream>
#include <string_view>
#include <optional>


enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,

};

std::optional<int> getNumberOfLegs(Animal animal);
std::string_view getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

std::ostream& operator<<(std::ostream& out, Animal animal);


int main()
{
    Animal cat { Animal::cat };
    Animal chicken { Animal::chicken };

    printNumberOfLegs(cat );
    printNumberOfLegs( chicken );

    return 0;
}


std::ostream& operator<<(std::ostream& out, Animal animal)
{
    out << getAnimalName(animal);
    return out;
}



std::string_view getAnimalName(Animal animal)
{
    using enum Animal;

    switch(animal)
    {
        case pig:return "pig";
        case chicken: return "chicken";
        case goat: return "goat";
        case cat: return "cat";
        case dog: return "dog";
        case duck: return "duck";

        default: return "???";
    }
}


std::optional<int> getNumberOfLegs(Animal animal)
{
    using enum Animal;
    
    switch(animal)
    {
        case pig:
        case goat:
        case cat:
        case dog:
            return 4;
        case chicken:
        case duck:
            return 2;

        default:
            return std::nullopt;
    }
}


void printNumberOfLegs(Animal animal)
{
    std::optional<int> legs { getNumberOfLegs(animal) };
    
    if(legs)
    {
        std::cout << "A " << animal << " has " << *legs << " legs.\n";
    }
    else 
    {
        std::cerr << "Animal name " << "\"" << animal << "\"" << " is not known.\n";
    }
}

