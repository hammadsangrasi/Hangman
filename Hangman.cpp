// Hangman.cpp
// Here we write the real code for the functions we declared in Hangman.h

#include "Hangman.h"
#include <iostream>   // For cout (printing to the screen)

// Constructor: sets up everything for a new game.
// The part after the colon is an "initializer list". It sets the starting values.
Hangman::Hangman(const std::string& word)
    : secretWord(word), guessedWord(word.size(), '_'), wrongCount(0) {
    // guessedWord starts as all underscores, one for each letter.
    // Example: for "cat" it becomes "___"
}

// Checks if a letter is in the secret word.
bool Hangman::makeGuess(char letter) {
    // Remember that this letter was tried
    allGuesses += letter;

    bool found = false;

    // Look at every position in the secret word
    for (size_t i = 0; i < secretWord.size(); i++) {
        if (secretWord[i] == letter) {
            guessedWord[i] = letter;  // Reveal the letter in that position
            found = true;
        }
    }

    // If the letter was not in the word, count it as a mistake
    if (!found) {
        wrongLetters += letter;
        wrongCount++;
    }

    return found;
}

// Checks if the letter was tried before.
bool Hangman::alreadyGuessed(char letter) const {
    // find() returns npos if the letter is NOT found
    return allGuesses.find(letter) != std::string::npos;
}

// The player wins when there are no underscores left.
bool Hangman::isWon() const {
    return guessedWord.find('_') == std::string::npos;
}

// The player loses when wrong guesses reach the maximum.
bool Hangman::isLost() const {
    return wrongCount >= MAX_WRONG;
}

// Returns the secret word.
std::string Hangman::getSecretWord() const {
    return secretWord;
}

// Prints the current state of the game.
void Hangman::display() const {
    // Each string below is one picture of the hangman.
    // The picture changes depending on how many wrong guesses were made.
    const std::string stages[MAX_WRONG + 1] = {
        // 0 wrong
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 1 wrong (head)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 2 wrong (body)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 3 wrong (left arm)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 4 wrong (right arm)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 5 wrong (left leg)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        // 6 wrong (right leg - game over)
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };

    std::cout << "\n" << stages[wrongCount] << "\n\n";

    // Print the word with a space between letters so it is easy to read
    std::cout << "Word: ";
    for (size_t i = 0; i < guessedWord.size(); i++) {
        std::cout << guessedWord[i] << ' ';
    }
    std::cout << "\n";

    // Print the wrong letters
    std::cout << "Wrong letters: ";
    for (size_t i = 0; i < wrongLetters.size(); i++) {
        std::cout << wrongLetters[i] << ' ';
    }
    std::cout << "\n";

    // Tell the player how many chances are left
    std::cout << "Chances left: " << (MAX_WRONG - wrongCount) << "\n";
}