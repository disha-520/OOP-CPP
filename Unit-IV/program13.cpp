#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens the file in read mode
    std::ifstream inputFile("missing_file.txt");

    // Checks whether the file was opened successfully
    if (!inputFile.is_open()) {

        // Displays an error message
        std::cerr << "Error: File could not be opened.\n";

        // Displays a message to check the file
        std::cerr << "Check whether missing_file.txt exists in the current folder.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Declares a string variable to store each line
    std::string line;

    // Reads the file one line at a time
    while (std::getline(inputFile, line)) {

        // Displays the current line
        std::cout << line << '\n';
    }

    // Checks whether the end of the file was reached
    if (inputFile.eof()) {

        // Displays a message when the end of file is reached normally
        std::cout << "End of file reached normally.\n";

    // Checks whether a serious input/output error occurred
    } else if (inputFile.bad()) {

        // Displays a serious file error message
        std::cerr << "A serious file I/O error occurred.\n";

    // Checks whether a logical file read error occurred
    } else if (inputFile.fail()) {

        // Displays a logical file read error message
        std::cerr << "A logical file read error occurred.\n";
    }

    // Returns 0 to indicate successful program execution
    return 0;
}