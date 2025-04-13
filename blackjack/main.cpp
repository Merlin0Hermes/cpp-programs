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
    if (dealer.score > Settings::bust)
    {
        std::cout << "The dealer went bust!\n";
        return true;
    }
    return false;
}

bool user_turn(Deck& deck, Player& user)
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";
        char choice{};
        std::cin >> choice;

        if (choice == 's')
            break;

        Card card { deck.deal_card() };
        user.score += card.value();
        std::cout << "You were dealt " << card << ".\tYou now have: " << user.score << "\n";
    }
    
    if (user.score > Settings::bust)
    {
        std::cout << "You went bust!\n";
        return true;
    }
    return false;
}


bool play_blackjack()
{
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.deal_card().value() }; // deal a card for dealer
    
    Player user { deck.deal_card().value() + deck.deal_card().value() }; // deal two cards for user

    std::cout << "The dealer is showing: " << dealer.score << "\n";
    std::cout << "You have score: " << user.score << "\n";

    bool user_bust { user_turn(deck, user) };
    if (user_bust == true)
        return false;
    
    bool dealer_bust { dealer_turn(deck, dealer) };
    if (dealer_bust == true)
        return true;
        
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