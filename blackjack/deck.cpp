#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include "deck.h"


std::string_view to_symbol(Card::Rank rank)
{
    static constexpr std::array<std::string_view, Card::max_ranks> rank_strings 
    {"A", "2", "3",  "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};

    return rank_strings[rank];
}

std::string_view to_symbol(Card::Suit suit)
{
    static constexpr std::array<std::string_view, Card::max_suits> suit_strings
    {"C", "D", "H", "S"};

    return suit_strings[suit];
}


int main()
{
    Deck deck{};

    for (auto a: deck.m_deck)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}