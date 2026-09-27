#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library
#include <limits>                     // Includes numeric limits library
#include <string>                     // Includes string library

int main() {                          // Main function where program execution starts

    // Opens students.txt in append mode
    std::ofstream outputFile("students.txt", std::ios::app);

    // Checks whether the file was opened successfully
    if (!outputFile) {

        // Displays an error message if the file could not be opened
        std::cerr << "Error: Could not open students.txt\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Declares a variable to store the student's roll number
    int rollNumber;

    // Declares a string variable to store the student's name
    std::string name;

    // Declares a variable to store the student's marks
    double marks;

    // Asks the user to enter the roll number
    std::cout << "Enter roll number: ";

    // Reads the roll number
    std::cin >> rollNumber;

    // Asks the user to enter the student's name
    std::cout << "Enter name: ";

    // Clears the remaining newline from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Reads the complete student name
    std::getline(std::cin, name);

    // Asks the user to enter the marks
    std::cout << "Enter marks: ";

    // Reads the marks
    std::cin >> marks;

    // Writes the student record into the file using | as a delimiter
    outputFile << rollNumber << '|' << name << '|' << marks << '\n';

    // Displays a success message
    std::cout << "Student record saved successfully.\n";

    // Returns 0 to indicate successful program execution
    return 0;
}