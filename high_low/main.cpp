// generate a random number between 2 user-inputted numbers and let user guess the number within 7 tries

#include <iostream>
#include "../Random.h"

void play_guessing_game(int max, int min, int guesses, int number);
bool play_again();
void change_limits(int &min, int &max, int &guesses);


int main()
{
    int min { 1 }, max { 100 }, guesses { 7 };


    while (true)
    {
        int target_number { Random::get(min, max)};        
        play_guessing_game(min, max, guesses, target_number);

        if (!(play_again()))
            break;

        std::cout << "Would you like to configure settings? (y/n) ";
        char choice{};
        std::cin >> choice;
        
        if (choice == 'y')
            change_limits(min, max, guesses);

    }
    return 0;

}


void play_guessing_game(int min, int max, int guesses, int number)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << min  
        << " and " << max << "." << " You have " << guesses << " tries to guess what it is.\n";

    for (int i = 1; i <= guesses; ++i)
    {
        std::cout << "Guess #" << i << ": ";
        int guess{};
        std::cin >> guess;

        if (guess > number)
        {
            std::cout << "Your guess is too high.\n";
        }
        else if (guess < number)
        {
            std::cout << "Your guess is too low.\n";
        }
        else 
        {
            std::cout << "Correct! You win!\n";
            return;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << number << ".\n";
}


bool play_again()
{
    while (true)
    {
        std::cout << "Would you like to play again? (y/n): ";
        char choice{};
        std::cin >> choice;

        if (choice == 'n')
            return false;
        else if (choice == 'y')
            return true;
    }

}


void change_limits(int &min, int &max, int &guesses)
{
    std::cout << "Enter the minimum number: ";
    std::cin >> min;

    std::cout << "Enter the maximum number: ";
    std::cin >> max;

    std::cout << "Enter the maximum number of guesses: ";
    std::cin >> guesses;
}