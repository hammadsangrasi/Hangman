// main.cpp
// This is where the program starts. It runs the game loop.

#include <iostream>
#include <string>
#include <cctype>      // For isalpha() and tolower()
#include "WordBank.h"
#include "Hangman.h"

int main() {
    std::cout << "=============================\n";
    std::cout << "     WELCOME TO HANGMAN!     \n";
    std::cout << "=============================\n";

    // Create one WordBank object. We will use it to get words.
    WordBank bank;

    char playAgain = 'y';

    // Keep playing as long as the player says yes
    while (playAgain == 'y') {

        // Make a new game with a random word
        Hangman game(bank.getRandomWord());

        // Keep going until the player wins or loses
        while (!game.isWon() && !game.isLost()) {
            game.display();

            std::cout << "\nGuess a letter: ";
            std::string input;
            std::cin >> input;

            // Only use the first character the player typed
            char letter = static_cast<char>(std::tolower(static_cast<unsigned char>(input[0])));

            // Check that it is a real letter (a to z)
            if (!std::isalpha(static_cast<unsigned char>(letter))) {
                std::cout << "Please type a letter only!\n";
                continue;  // Go back to the start of the loop
            }

            // Check if the player already tried this letter
            if (game.alreadyGuessed(letter)) {
                std::cout << "You already tried '" << letter << "'. Try another one.\n";
                continue;
            }

            // Make the guess and tell the player the result
            if (game.makeGuess(letter)) {
                std::cout << "Good job! '" << letter << "' is in the word.\n";
            } else {
                std::cout << "Sorry, '" << letter << "' is not in the word.\n";
            }
        }

        // The game is over. Show the final picture and the result.
        game.display();

        if (game.isWon()) {
            std::cout << "\nYou won! The word was: " << game.getSecretWord() << "\n";
        } else {
            std::cout << "\nYou lost! The word was: " << game.getSecretWord() << "\n";
        }

        // Ask if the player wants another round
        std::cout << "\nPlay again? (y/n): ";
        std::string answer;
        std::cin >> answer;
        playAgain = static_cast<char>(std::tolower(static_cast<unsigned char>(answer[0])));
    }

    std::cout << "\nThanks for playing. Goodbye!\n";
    return 0;
}