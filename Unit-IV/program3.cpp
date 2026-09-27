#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library

int main() {                          // Main function where program execution starts

    // Opens message.txt in append mode
    std::ofstream outputFile("message.txt", std::ios::app);

    // Checks whether the file was opened successfully
    if (!outputFile) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open message.txt for appending\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Adds a new line at the end of the file
    outputFile << "This line was added using append mode.\n";

    // Closes the output file
    outputFile.close();

    // Displays a success message on the console
    std::cout << "New line appended successfully.\n";

    // Returns 0 to indicate successful program execution
    return 0;
}