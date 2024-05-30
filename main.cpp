#include <iostream>
#include "GenerateNumber.h"

void printIntroduction() {
    std::cout << "Hello, welcome to the Number Guessing Game!" << std::endl;
    std::cout << "You can choose to guess a random number within a range or an entirely random number." << std::endl;
}

void getUserChoice(int &choice) {
    std::cout << "Press 1 to guess a random number within a range, or 2 to guess an entirely random number: ";
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid input. Please enter 1 or 2: ";
        std::cin >> choice;
    }
}

void getRange(int &low, int &high) {
    std::cout << "Enter the range (low high) in which you want to guess the number: ";
    std::cin >> low >> high;

    while (low >= high) {
        std::cout << "Invalid range. Ensure the low value is less than the high value. Enter the range again: ";
        std::cin >> low >> high;
    }

    std::cout << "Your chosen range is: " << low << " - " << high << std::endl;
}

int main() {
    printIntroduction();

    int choice;
    getUserChoice(choice);

    GenerateNumber generator;
    generator.setNumber();
    int number = generator.getRandomNumber();

    int low, high;
    if (choice == 1) {
        getRange(low, high);
        number = number % (high - low + 1) + low;
    }

    std::cout << "Guess the number!" << std::endl;

    bool guessedCorrectly = false;
    int userGuess;
    while (!guessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > number) {
            std::cout << "Too High" << std::endl;
        } else if (userGuess < number) {
            std::cout << "Too Low" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number correctly." << std::endl;
            guessedCorrectly = true;
        }
    }

    std::cout << "The guessed number was: " << number << std::endl;
    std::cout << "Thank you for playing the Number Guessing Game!" << std::endl;

    return 0;
}
