#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "\n\n---Guess the Number Game---" << endl;
    cout << " Try to guess it! Number between 1 and 100." << endl;
    
    srand(time(0)); 
    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess == secretNumber) {
            cout << "\nCongratulations! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts." << endl;
        } else if (guess < secretNumber) {
            cout << "Low! Try guessing higher." << endl;
        } else {
            cout << "High! Try guessing lower." << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}