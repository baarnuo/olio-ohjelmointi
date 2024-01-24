#include "game.h"

Game::Game(int maxNumber):
    maxNumber(maxNumber),
    playerGuess(0),
    randomNumber(0),
    numOfGuesses(0)
{
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
    srand(time(NULL));
    randomNumber = rand() % maxNumber + 1;
}

void Game::play()
{
    while (playerGuess != randomNumber) {
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;
        if (cin.fail()) {
            cout << "Invalid input. Enter a number." << endl;
            cin.clear();
            cin.ignore(256, '\n');
        } else {
            numOfGuesses++;
            if (playerGuess > randomNumber) {
                cout << "Too high." << endl;
            } else if (playerGuess < randomNumber) {
                cout << "Too low." << endl;
            } else {
                cout << "Correct!" << endl;
                break;
            }
        }
    }
    printGameResult();
}

void Game::printGameResult()
{
    cout << "Number of guesses: " << numOfGuesses << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}
