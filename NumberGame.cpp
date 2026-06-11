#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time() to seed the random number generator

using namespace std;

void playGame(int &totalRoundsWon, int &totalScore) {
    // 1. Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int userGuess = 0;
    int attempts = 0;
    
    // 5. Limit the number of attempts
    const int MAX_ATTEMPTS = 7; 
    bool hasWon = false;

    cout << "\n=========================================" << endl;
    cout << "I have generated a number between 1 and 100." << endl;
    cout << "You have a maximum of " << MAX_ATTEMPTS << " attempts to guess it!" << endl;
    cout << "=========================================" << endl;

    // 4. Repeat until the user guesses correctly or runs out of attempts
    while (attempts < MAX_ATTEMPTS) {
        // 2. Prompt the user for their guess
        cout << "\nAttempt " << (attempts + 1) << "/" << MAX_ATTEMPTS << ". Enter your guess: ";
        
        // Input validation to ensure the user enters an integer
        if (!(cin >> userGuess)) {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            continue;
        }

        attempts++;

        // 3. Compare the guess and provide feedback
        if (userGuess == randomNumber) {
            cout << " Congratulations! You guessed the correct number in " << attempts << " attempts!" << endl;
            hasWon = true;
            totalRoundsWon++;
            
            // 7. Score Calculation: Higher score for fewer attempts
            int roundScore = (MAX_ATTEMPTS - attempts + 1) * 10; 
            totalScore += roundScore;
            cout << "Round Score: " << roundScore << " points." << endl;
            break;
        } 
        else if (userGuess > randomNumber) {
            cout << " Too high! Try a lower number." << endl;
        } 
        else {
            cout << " Too low! Try a higher number." << endl;
        }
    }

    if (!hasWon) {
        cout << "\n Game Over! You've run out of attempts." << endl;
        cout << "The correct number was: " << randomNumber << endl;
    }
}

int main() {
    // Seed the random number generator using the current system time
    srand(static_cast<unsigned int>(time(0)));

    int totalRoundsWon = 0;
    int totalScore = 0;
    char playAgainChoice;

    cout << " WELCOME TO THE NUMBER GUESSING GAME! " << endl;

    // 6. Option for multiple rounds
    do {
        playGame(totalRoundsWon, totalScore);

        // Display current overall standings
        cout << "\n-----------------------------------------" << endl;
        cout << " CURRENT STATS -> Rounds Won: " << totalRoundsWon << " | Total Score: " << totalScore << endl;
        cout << "-----------------------------------------" << endl;

        cout << "\nDo you want to play another round? (y/n): ";
        cin >> playAgainChoice;

    } while (playAgainChoice == 'y' || playAgainChoice == 'Y');

    cout << "\nThank you for playing! Final Score: " << totalScore << " | Total Rounds Won: " << totalRoundsWon << endl;
    cout << "Goodbye! " << endl;

    return 0;
}