#ifndef POTION_H
#define POTION_H

#include <iostream>
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

    std::string_view type_name(Type type) const
    {
        static constexpr std::string_view type_names[] {"health", "strength", "poison"};
        return type_names[type];
    }

    std::string_view size_name(Size size) const
    {
        static constexpr std::string_view size_names[] {"Small", "Medium", "Large"};
        return size_names[size];
    }

    static Potion random_potion() 
    {
        Type rand_type {static_cast<Type>(Random::get(0, max_types - 1))};
        Size rand_size {static_cast<Size>(Random::get(0, max_size - 1))};
        return Potion{rand_type, rand_size};
    }

    std::string name() const
    {
        std::stringstream ss{};
        ss << size_name(m_size) << " potion of " << type_name(m_type);
        return ss.str();
    }

private:
    Type m_type{};
    Size m_size{};

};

#endif
