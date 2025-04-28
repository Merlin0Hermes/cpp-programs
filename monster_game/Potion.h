#ifndef POTION_H
#define POTION_H

#include <string>
#include <string_view>
#include <sstream>
#include "../Random.h"

class Potion
{
public:
    enum Type
    {
        health,
        strength,
        poison,

        max_types
    };

    enum Size
    {
        small,
        medium,
        large,

        max_size
    };

    Potion(Type type, Size size)
    :m_type{type}
    ,m_size{size}
    {
    }

    Type type() const { return m_type; }
    Size size() const { return m_size; }

    std::string_view type_name() const
    {
        static constexpr std::string_view name[] {"health", "strength", "poison"};
        return name[m_type];
    }

    std::string_view size_name() const
    {
        static constexpr std::string_view name[] {"Small", "Medium", "Large"};
        return name[m_size];
    }

    static Potion random_potion() 
    {
        Type rand_type {static_cast<Type>(Random::get(0, max_types))};
        Size rand_size {static_cast<Size>(Random::get(0, max_size))};
        return Potion(rand_type, rand_size);
    }

    std::string name() const
    {
        std::stringstream ss{};
        ss << size_name() << " potion of " << type_name();
        return ss.str();
    }

private:
    Type m_type{};
    Size m_size{};

};

#endif
