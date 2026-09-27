#include <cctype>                    // Includes character handling functions
#include <fstream>                   // Includes file stream library
#include <iostream>                  // Includes input-output library
#include <string>                    // Includes string library

// Function to check whether a character is a vowel
bool isVowel(char ch) {

    // Converts the character to lowercase
    ch = static_cast<char>(
        std::tolower(static_cast<unsigned char>(ch))
    );

    // Returns true if the character is a vowel
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {                         // Main function where program execution starts

    // Stores the name of the file entered by the user
    std::string fileName;

    // Asks the user to enter the file name
    std::cout << "Enter file name: ";

    // Reads the complete file name
    std::getline(std::cin, fileName);

    // Opens the selected file for reading
    std::ifstream inputFile(fileName);

    // Checks whether the file was opened successfully
    if (!inputFile) {

        // Displays an error message
        std::cerr << "Error: Could not open " << fileName << '\n';

        // Returns 1 to indicate an error
        return 1;
    }

    // Stores the number of lines
    std::size_t lines = 0;

    // Stores the number of words
    std::size_t words = 0;

    // Stores the number of characters
    std::size_t characters = 0;

    // Stores the number of vowels
    std::size_t vowels = 0;

    // Stores the number of digits
    std::size_t digits = 0;

    // Stores the number of spaces
    std::size_t spaces = 0;

    // Keeps track of whether the program is inside a word
    bool insideWord = false;

    // Stores one character at a time
    char ch;

    // Reads the file one character at a time
    while (inputFile.get(ch)) {

        // Increases the character count
        ++characters;

        // Checks whether the character is a newline
        if (ch == '\n') {

            // Increases the line count
            ++lines;
        }

        // Checks whether the character is whitespace
        if (std::isspace(static_cast<unsigned char>(ch))) {

            // Checks whether the whitespace is a normal space
            if (ch == ' ') {

                // Increases the space count
                ++spaces;
            }

            // Marks that the program is outside a word
            insideWord = false;

        } else if (!insideWord) {

            // Increases the word count when a new word starts
            ++words;

            // Marks that the program is inside a word
            insideWord = true;
        }

        // Checks whether the character is an alphabet
        if (std::isalpha(static_cast<unsigned char>(ch)) && isVowel(ch)) {

            // Increases the vowel count
            ++vowels;
        }

        // Checks whether the character is a digit
        if (std::isdigit(static_cast<unsigned char>(ch))) {

            // Increases the digit count
            ++digits;
        }
    }

    // Checks whether the file contains at least one character
    if (characters > 0) {

        // Clears the stream state
        inputFile.clear();

        // Moves the input pointer to the last character
        inputFile.seekg(-1, std::ios::end);

        // Stores the last character
        char lastCharacter;

        // Reads the last character
        inputFile.get(lastCharacter);

        // Checks whether the last character is not a newline
        if (lastCharacter != '\n') {

            // Counts the last line
            ++lines;
        }
    }

    // Displays the heading
    std::cout << "\nFile Statistics\n";

    // Displays the number of lines
    std::cout << "Lines: " << lines << '\n';

    // Displays the number of words
    std::cout << "Words: " << words << '\n';

    // Displays the number of characters
    std::cout << "Characters: " << characters << '\n';

    // Displays the number of vowels
    std::cout << "Vowels: " << vowels << '\n';

    // Displays the number of digits
    std::cout << "Digits: " << digits << '\n';

    // Displays the number of spaces
    std::cout << "Spaces: " << spaces << '\n';

    // Returns 0 to indicate successful program execution
    return 0;
}