#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens message.txt for reading
    std::ifstream sourceFile("message.txt");

    // Creates message_copy.txt for writing
    std::ofstream destinationFile("message_copy.txt");

    // Checks whether the source file was opened successfully
    if (!sourceFile) {

        // Displays an error message
        std::cerr << "Error: Could not open source file.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Checks whether the destination file was created successfully
    if (!destinationFile) {

        // Displays an error message
        std::cerr << "Error: Could not create destination file.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Declares a string variable to store each line
    std::string line;

    // Reads the source file one line at a time
    while (std::getline(sourceFile, line)) {

        // Writes each line into the destination file
        destinationFile << line << '\n';
    }

    // Displays a success message on the console
    std::cout << "File copied successfully to message_copy.txt\n";

    // Returns 0 to indicate successful program execution
    return 0;
}