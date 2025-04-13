// simplified version of blackjack game

#include <iostream>
#include "deck.h"
#include "../Random.h"

namespace Settings
{
    int bust {21}; // value after which player will bust
    int dealer_stop {17}; // value after which dealer can't draw any more cards
}


struct Player
{
    int score{0};
};

bool dealer_turn(Deck& deck, Player& dealer)
{
    while(dealer.score < Settings::dealer_stop)
    {
        Card card { deck.deal_card() };
        dealer.score += card.value();
        std::cout << "The dealer flips a " << card << ".\tThey now have: " << dealer.score << "\n";
    }
    return dealer.score > Settings::bust; // returns if dealer went bust
}

bool play_blackjack()
{
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.deal_card().value() }; // deal a card for dealer
    
    Player user { deck.deal_card().value() + deck.deal_card().value() }; // deal two cards for user

    std::cout << "The dealer is showing: " << dealer.score << "\n";
    std::cout << "You have score: " << user.score << "\n";

    bool bust { dealer_turn(deck, dealer) };
    if (bust)
        std::cout << "The dealer went bust!\n";

    return user.score > dealer.score;
}


int main()
{
    bool won { play_blackjack() };

    if (won)
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

}