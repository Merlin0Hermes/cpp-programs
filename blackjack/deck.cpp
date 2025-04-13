#include <iostream>
#include <array>
#include <algorithm>
#include <string_view>
#include <cassert>
#include "deck.h"
#include "../Random.h"


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

int Card::value() const
{
    static constexpr std::array<int, max_ranks> 
        card_values{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    return card_values[rank];
}   

Card Deck::deal_card()
{
    assert(m_current != deck_size && "Deck::deal_card() ran out of cards");
    return m_deck[m_current++];
}

void Deck::shuffle()
{
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
    m_current = 0;
}

int main()
{
    Deck deck{};
    std::cout << deck.deal_card() << ' ' << deck.deal_card() << ' ' << deck.deal_card() << '\n';

    deck.shuffle();
    std::cout << deck.deal_card() << ' ' << deck.deal_card() << ' ' << deck.deal_card() << '\n';

    return 0;
}