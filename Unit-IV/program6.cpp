#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens message.txt for reading
    std::ifstream inputFile("message.txt");

    // Checks whether the file was opened successfully
    if (!inputFile) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open message.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Declares a variable to store the word to be searched
    std::string searchWord;

    // Asks the user to enter a word
    std::cout << "Enter word to search: ";

    // Reads the search word from the user
    std::cin >> searchWord;

    // Declares a variable to store each word read from the file
    std::string word;

    // Stores the number of occurrences of the searched word
    int count = 0;

    // Reads words from the file until the end of the file
    while (inputFile >> word) {

        // Checks whether the current word matches the search word
        if (word == searchWord) {

            // Increases the occurrence count
            ++count;
        }
    }

    // Displays the number of times the word occurred
    std::cout << "The word '" << searchWord << "' occurred "
              << count << " time(s).\n";

    // Returns 0 to indicate successful program execution
    return 0;
}