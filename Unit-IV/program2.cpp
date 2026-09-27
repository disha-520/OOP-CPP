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

    // Declares a string variable to store each line
    std::string line;

    // Displays the heading
    std::cout << "File Content:\n";

    // Reads the file line by line
    while (std::getline(inputFile, line)) {

        // Displays the current line
        std::cout << line << '\n';
    }

    // Closes the input file
    inputFile.close();

    // Returns 0 to indicate successful execution
    return 0;
}