#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum);

int main() {
    int maxNumber = 40;
    int inputCount = game(maxNumber);

    cout << "Amount of guesses: " << inputCount << endl;

    return 0;
}

int game(int maxnum) {
    int rangeMax = maxnum;
    int userInput = 0;
    int inputCount = 0;

    srand(time(NULL));

    int randomNumber = rand() % rangeMax + 1;

    cout << "Guess a number between 1 and " << rangeMax << ": " << endl;
    while (userInput != randomNumber) {
        cin >> userInput;
        inputCount++;
        if (userInput > randomNumber) {
            cout << "Too high." << endl;
        } else if (userInput < randomNumber) {
            cout << "Too low." << endl;
        } else {
            cout << "Correct!" << endl;
            break;
        }
        cout << "Guess again: " << endl;
    }
    return inputCount;
}
