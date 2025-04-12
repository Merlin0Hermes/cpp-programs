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
    // Print one card
    Card card { Card::rank_5, Card::suit_heart };
    std::cout << card << '\n';

    // Print all cards
    for (auto suit : Card::all_suits)
        for (auto rank : Card::all_ranks)
            std::cout << Card { rank, suit } << ' ';
    std::cout << '\n';

    return 0;
}