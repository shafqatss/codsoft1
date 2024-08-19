#include <iostream>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <limits>  // For std::numeric_limits

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Generate a random number between 1 and 100
    int number_to_guess = std::rand() % 100 + 1;
    int guess = 0;
    
    std::cout << "Welcome to the 'Guess the Number' game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;

    while (true) {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;

        // Check if the input is a valid number
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        // Check if the guess is within the valid range
        if (guess < 1 || guess > 100) {
            std::cout << "Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        // Check the guess
        if (guess < number_to_guess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > number_to_guess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number!" << std::endl;
            break;
        }
    }

    return 0;
}