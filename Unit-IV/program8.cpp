#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <sstream>                    // Includes string stream library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens students.txt for reading
    std::ifstream inputFile("students.txt");

    // Checks whether the file was opened successfully
    if (!inputFile) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open students.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Stores the roll number to search
    int targetRollNumber;

    // Asks the user to enter the roll number
    std::cout << "Enter roll number to search: ";

    // Reads the target roll number
    std::cin >> targetRollNumber;

    // Stores each line read from the file
    std::string line;

    // Keeps track of whether the record was found
    bool found = false;

    // Reads the file one line at a time
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

            // Converts the marks from text to double
            double marks = std::stod(marksText);

            // Checks whether the roll number matches the searched number
            if (rollNumber == targetRollNumber) {

                // Displays that the record was found
                std::cout << "Record Found\n";

                // Displays the roll number
                std::cout << "Roll Number: " << rollNumber << '\n';

                // Displays the student's name
                std::cout << "Name: " << name << '\n';

                // Displays the student's marks
                std::cout << "Marks: " << marks << '\n';

                // Marks the record as found
                found = true;

                // Stops searching after finding the record
                break;
            }
        }
    }

    // Checks whether the record was not found
    if (!found) {

        // Displays a message when the record does not exist
        std::cout << "Student record not found.\n";
    }

    // Returns 0 to indicate successful program execution
    return 0;
}