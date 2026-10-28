// WordBank.h
// This class stores a list of words and gives us a random one.

#pragma once   // Stops this file from being included twice by mistake

#include <string>   // For using std::string (text)
#include <vector>   // For using std::vector (a list that can grow)
#include <cstdlib>  // For rand() and srand() (random numbers)
#include <ctime>    // For time() (used to change the random numbers each run)

class WordBank {
private:
    // A list of all the words the game can pick from.
    // It is private so nobody outside the class can mess with it.
    std::vector<std::string> words;

public:
    // Constructor: runs automatically when we create a WordBank object.
    WordBank() {
        // Fill the list with some words
        words = {
            "apple", "banana", "computer", "keyboard", "programming",
            "elephant", "guitar", "mountain", "rainbow", "pencil",
            "football", "chocolate", "umbrella", "dolphin", "castle"
        };

        // Set the random seed using the current time.
        // Without this, we would get the same "random" word every time.
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    // Picks one random word from the list and returns it.
    // "const" means this function does not change anything inside the class.
    std::string getRandomWord() const {
        int index = std::rand() % words.size();  // A number from 0 to size-1
        return words[index];
    }
};