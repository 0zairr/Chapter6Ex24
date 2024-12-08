/*
File name: Chapter6Ex24.cpp
Programmer: Ozair Ghaissi
Date: 11/27/2024
*/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Function prototypes
int getComputerChoice();
string choiceToString(int choice);
int getUserChoice();
void displayChoices(int userChoice, int computerChoice);
void determineWinner(int userChoice, int computerChoice);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int userChoice, computerChoice;

    cout << "Welcome to Rock, Paper, Scissors!\n";

    do {
        // Get computer's and user's choices
        computerChoice = getComputerChoice();
        userChoice = getUserChoice();

        // Display choices
        displayChoices(userChoice, computerChoice);

        // Determine and display the winner
        determineWinner(userChoice, computerChoice);

    } while (userChoice == computerChoice); // Repeat if there's a tie

    return 0;
}

// Generates a random choice for the computer (1 = Rock, 2 = Paper, 3 = Scissors)
int getComputerChoice() {
    return rand() % 3 + 1;
}

// Converts numerical choice to string for display
string choiceToString(int choice) {
    if (choice == 1) return "Rock";
    else if (choice == 2) return "Paper";
    else if (choice == 3) return "Scissors";
    else return "Invalid Choice";
}

// Gets the user's choice
int getUserChoice() {
    int choice;
    do {
        cout << "\nEnter your choice:\n";
        cout << "1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice! Please choose again.\n";
        }
    } while (choice < 1 || choice > 3);

    return choice;
}

// Displays the user's and computer's choices
void displayChoices(int userChoice, int computerChoice) {
    cout << "\nYou chose: " << choiceToString(userChoice) << endl;
    cout << "Computer chose: " << choiceToString(computerChoice) << endl;
}

// Determines and displays the winner
void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
        return;
    }

    if ((userChoice == 1 && computerChoice == 3) || // Rock beats Scissors
        (userChoice == 3 && computerChoice == 2) || // Scissors beats Paper
        (userChoice == 2 && computerChoice == 1)) { // Paper beats Rock
        cout << "You win!\n";
    }
    else {
        cout << "Computer wins!\n";
    }
}


