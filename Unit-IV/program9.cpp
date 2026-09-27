#include <cstdio>                     // Includes functions for file operations
#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <sstream>                    // Includes string stream library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens students.txt for reading
    std::ifstream inputFile("students.txt");

    // Creates a temporary file for storing updated records
    std::ofstream temporaryFile("students_temp.txt");

    // Checks whether both files were opened successfully
    if (!inputFile || !temporaryFile) {

        // Displays an error message
        std::cerr << "Error: Could not open file(s).\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Stores the roll number of the student to update
    int targetRollNumber;

    // Stores the updated marks
    double updatedMarks;

    // Asks the user to enter the roll number
    std::cout << "Enter roll number to update: ";

    // Reads the target roll number
    std::cin >> targetRollNumber;

    // Asks the user to enter the updated marks
    std::cout << "Enter updated marks: ";

    // Reads the updated marks
    std::cin >> updatedMarks;

    // Stores each line read from the original file
    std::string line;

    // Keeps track of whether the student record was found
    bool found = false;

    // Reads the original file one line at a time
    while (std::getline(inputFile, line)) {

        // Creates a string stream from the current record
        std::stringstream record(line);

        // Stores the roll number as text
        std::string rollText;

        // Stores the student's name
        std::string name;

        // Stores the marks as text
        std::string marksText;

        // Reads the three fields separated by the | delimiter
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Converts the roll number from text to integer
            int rollNumber = std::stoi(rollText);

            // Checks whether the roll number matches the target
            if (rollNumber == targetRollNumber) {

                // Writes the updated record to the temporary file
                temporaryFile << rollNumber << '|' << name << '|'
                              << updatedMarks << '\n';

                // Marks the record as found
                found = true;

            } else {

                // Writes the unchanged record to the temporary file
                temporaryFile << line << '\n';
            }
        }
    }

    // Closes the original input file
    inputFile.close();

    // Closes the temporary file
    temporaryFile.close();

    // Checks whether the student record was not found
    if (!found) {

        // Deletes the temporary file
        std::remove("students_temp.txt");

        // Displays a message that no update was performed
        std::cout << "Student record not found. No update performed.\n";

        // Returns 0 because the program completed normally
        return 0;
    }

    // Removes the old students.txt file
    if (std::remove("students.txt") != 0) {

        // Displays an error if the old file could not be removed
        std::cerr << "Error: Could not remove old students.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Renames the temporary file as students.txt
    if (std::rename("students_temp.txt", "students.txt") != 0) {

        // Displays an error if the temporary file could not be renamed
        std::cerr << "Error: Could not rename temporary file.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Displays a success message
    std::cout << "Student marks updated successfully.\n";

    // Returns 0 to indicate successful program execution
    return 0;
}