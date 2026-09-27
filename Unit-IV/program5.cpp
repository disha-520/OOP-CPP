#include <cctype>                    // Includes character handling functions
#include <fstream>                   // Includes file stream library
#include <iostream>                  // Includes input-output library
#include <string>                    // Includes string library

int main() {                         // Main function where program execution starts

    // Opens message.txt for reading
    std::ifstream inputFile("message.txt");

    // Checks whether the file was opened successfully
    if (!inputFile) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open message.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Stores the number of lines in the file
    std::size_t lineCount = 0;

    // Stores the number of words in the file
    std::size_t wordCount = 0;

    // Stores the number of characters in the file
    std::size_t characterCount = 0;

    // Keeps track of whether the program is currently inside a word
    bool insideWord = false;

    // Stores one character at a time
    char ch;

    // Reads the file one character at a time
    while (inputFile.get(ch)) {

        // Increases the character count
        ++characterCount;

        // Checks whether the character is a newline
        if (ch == '\n') {

            // Increases the line count
            ++lineCount;
        }

        // Checks whether the character is whitespace
        if (std::isspace(static_cast<unsigned char>(ch))) {

            // Marks that the program is outside a word
            insideWord = false;

        } else if (!insideWord) {

            // Increases the word count when a new word starts
            ++wordCount;

            // Marks that the program is inside a word
            insideWord = true;
        }
    }

    // Checks whether the file contains at least one character
    if (characterCount > 0) {

        // Clears the stream state
        inputFile.clear();

        // Moves the file pointer to the last character
        inputFile.seekg(-1, std::ios::end);

        // Stores the last character of the file
        char lastCharacter;

        // Reads the last character
        inputFile.get(lastCharacter);

        // Checks whether the last character is not a newline
        if (lastCharacter != '\n') {

            // Counts the last line
            ++lineCount;
        }
    }

    // Displays the total number of lines
    std::cout << "Lines: " << lineCount << '\n';

    // Displays the total number of words
    std::cout << "Words: " << wordCount << '\n';

    // Displays the total number of characters
    std::cout << "Characters: " << characterCount << '\n';

    // Returns 0 to indicate successful program execution
    return 0;
}