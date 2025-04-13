// simplified version of blackjack game

#include <iostream>
#include "deck.h"
#include "../Random.h"


struct Player
{
    int score{0};
};

bool play_blackjack()
{
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.deal_card().value() }; // deal a card for dealer
    
    Player user { deck.deal_card().value() + deck.deal_card().value() }; // deal two cards for user

    std::cout << "The dealer is showing: " << dealer.score << "\n";
    std::cout << "You have score: " << user.score << "\n";
}


int main()
{
    bool won { play_blackjack() };

    if (won)
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";

}