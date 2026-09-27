#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library

int main() {                          // Main function where program execution starts

    // Creates and opens message.txt for writing
    std::ofstream outputFile("message.txt");

    // Checks whether the file was created/opened successfully
    if (!outputFile) {

        // Displays an error message if the file could not be created
        std::cerr << "Error: Could not create message.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Writes the first line into the file
    outputFile << "Welcome to C++ File Handling\n";

    // Writes the second line into the file
    outputFile << "This is the first line written to a file.\n";

    // Writes the third line into the file
    outputFile << "Files store data permanently.\n";

    // Closes the file
    outputFile.close();

    // Displays a success message on the console
    std::cout << "Data written successfully to message.txt\n";

    // Returns 0 to indicate successful program execution
    return 0;
}