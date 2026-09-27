#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens navigation.txt for both reading and writing
    std::fstream file("navigation.txt", std::ios::in | std::ios::out | std::ios::trunc);

    // Checks whether the file was opened successfully
    if (!file) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open navigation.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Writes the characters ABCDE into the file
    file << "ABCDE";

    // Displays the current output position
    std::cout << "Output position after writing: " << file.tellp() << '\n';

    // Ensures that the written data is stored properly
    file.flush();

    // Moves the input position to the beginning of the file
    file.seekg(0, std::ios::beg);

    // Declares a character variable to store the first character
    char firstCharacter;

    // Reads the first character from the file
    file.get(firstCharacter);

    // Displays the first character
    std::cout << "First character: " << firstCharacter << '\n';

    // Displays the current input position
    std::cout << "Input position after reading one character: "
              << file.tellg() << '\n';

    // Moves the input position to character position 2
    file.seekg(2, std::ios::beg);

    // Declares a character variable to store the third character
    char thirdCharacter;

    // Reads the character at position 2
    file.get(thirdCharacter);

    // Displays the character at position 2
    std::cout << "Character at position 2: " << thirdCharacter << '\n';

    // Moves the output position to position 5
    file.seekp(5, std::ios::beg);

    // Writes F at position 5
    file << "F";

    // Closes the file
    file.close();

    // Displays a completion message
    std::cout << "Navigation completed. Check navigation.txt\n";

    // Returns 0 to indicate successful program execution
    return 0;
}