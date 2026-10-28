// Hangman.h
// This file only DECLARES the Hangman class (the plan of the class).
// The real work of each function is written in Hangman.cpp.

#pragma once   // Stops this file from being included twice by mistake

#include <string>

class Hangman {
private:
    // The maximum number of wrong guesses allowed before the player loses.
    static const int MAX_WRONG = 6;

    std::string secretWord;     // The word the player must find
    std::string guessedWord;    // What the player sees so far, like "a _ _ l e"
    std::string wrongLetters;   // All the wrong letters the player tried
    std::string allGuesses;     // Every letter tried (right or wrong)
    int wrongCount;             // How many wrong guesses so far

public:
    // Constructor: starts a new game with the given secret word.
    Hangman(const std::string& word);

    // Checks one letter. Returns true if the letter is in the word.
    bool makeGuess(char letter);

    // Returns true if this letter was already tried before.
    bool alreadyGuessed(char letter) const;

    // Returns true if the player found all the letters.
    bool isWon() const;

    // Returns true if the player ran out of chances.
    bool isLost() const;

    // Shows the hangman picture, the word and the wrong letters.
    void display() const;

    // Returns the secret word (used to show it when the player loses).
    std::string getSecretWord() const;
};