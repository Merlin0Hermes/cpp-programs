#ifndef DECK_H
#define DECK_H

#include <array>
#include <iostream>

struct Card
{
    enum Rank 
    {
        rank_ace,
        rank_2, 
        rank_3, 
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };    

    static constexpr std::array<Rank, max_ranks> all_ranks {
        rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6,
        rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king
    };

    static constexpr std::array<Suit, max_suits> all_suits {
        suit_club, suit_diamond, suit_heart, suit_spade
    };

    Rank rank{};
    Suit suit{};

    friend std::string_view to_symbol(Card::Suit suit);
    friend std::string_view to_symbol(Card::Rank rank);

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        std::cout << to_symbol(card.rank) << to_symbol(card.suit);
        return out;
    }

    int value() const
    {
        static constexpr std::array<int, max_ranks> 
            card_values{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return card_values[rank];
    }   

};


#endif