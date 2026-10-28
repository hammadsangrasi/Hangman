# Hangman Game in C++

A simple console Hangman game written in C++ using Object-Oriented Programming (OOP). The computer picks a random word, and you try to guess it one letter at a time before the hangman is fully drawn.

## Features

- Random word picked from a built-in word list
- ASCII drawing of the hangman that grows with each wrong guess
- 6 chances per round
- Shows the letters you guessed wrong
- Ignores repeated guesses and non-letter input
- Play again without restarting the program

## OOP Concepts Used

- **Classes and objects:** `WordBank` and `Hangman` are separate classes
- **Encapsulation:** game data is `private` and used only through public functions
- **Constructors:** set up each class when an object is created
- **Const member functions:** functions that only read data are marked `const`
- **Header and source files:** class declarations (`.h`) are kept apart from their code (`.cpp`)

## Project Structure

```
HangmanGame/
├── main.cpp       # Starts the program and runs the game loop
├── Hangman.h      # Hangman class declaration
├── Hangman.cpp    # Hangman class code
└── WordBank.h     # WordBank class (list of words + random pick)
```

## Requirements

- A C++ compiler such as `g++` (MinGW / MSYS2 on Windows, GCC on Linux, Xcode tools on Mac)
- C++11 or newer

## How to Build and Run

Open a terminal in the project folder and compile:

```
g++ main.cpp Hangman.cpp -o hangman
```

Run on Windows (PowerShell):

```
.\hangman.exe
```

Run on Mac or Linux:

```
./hangman
```

## How to Play

1. The game shows blanks for the secret word, like `_ _ _ _ _`.
2. Type one letter and press Enter.
3. A correct letter fills in its blanks. A wrong letter adds a part to the hangman.
4. You win by finding every letter. You lose after 6 wrong guesses.
5. Type `y` at the end to play again, or `n` to quit.

## Example

```
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

Word: _ a _ _ _ e
Wrong letters: x z
Chances left: 4
```

## Ideas for Improvement

- Add more words or load them from a text file
- Add difficulty levels
- Add a score counter across rounds
- Add word categories (animals, food, countries)

## Author

Made by a C++ beginner as a learning project.
