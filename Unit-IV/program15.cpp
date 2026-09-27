#include <cstdio>                         // Includes functions for file operations
#include <fstream>                        // Includes file stream library
#include <iostream>                       // Includes input-output library
#include <limits>                         // Includes numeric limits
#include <sstream>                        // Includes string stream library
#include <string>                         // Includes string library

// Function to add a new student record
void addStudent() {

    // Opens the student record file in append mode
    std::ofstream outputFile("student_records.txt", std::ios::app);

    // Checks whether the file was opened successfully
    if (!outputFile) {

        // Displays an error message
        std::cerr << "Error: Could not open student_records.txt\n";

        // Exits the function
        return;
    }

    // Stores the student's roll number
    int rollNumber;

    // Stores the student's name
    std::string name;

    // Stores the student's marks
    double marks;

    // Asks the user to enter roll number
    std::cout << "Enter roll number: ";

    // Reads the roll number
    std::cin >> rollNumber;

    // Asks the user to enter name
    std::cout << "Enter name: ";

    // Removes the remaining newline from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Reads the complete name
    std::getline(std::cin, name);

    // Asks the user to enter marks
    std::cout << "Enter marks: ";

    // Reads the marks
    std::cin >> marks;

    // Stores the student record in the file
    outputFile << rollNumber << '|' << name << '|' << marks << '\n';

    // Displays success message
    std::cout << "Record added successfully.\n";
}

// Function to display all student records
void displayStudents() {

    // Opens the student record file for reading
    std::ifstream inputFile("student_records.txt");

    // Checks whether the file exists
    if (!inputFile) {

        // Displays message if no file is found
        std::cout << "No student record file found.\n";

        // Exits the function
        return;
    }

    // Stores one complete line from the file
    std::string line;

    // Displays table heading
    std::cout << "\nRoll No.\tName\t\tMarks\n";

    // Displays a separator line
    std::cout << "----------------------------------------\n";

    // Reads the file one line at a time
    while (std::getline(inputFile, line)) {

        // Creates a string stream from the current line
        std::stringstream record(line);

        // Stores the roll number as text
        std::string rollText;

        // Stores the student name
        std::string name;

        // Stores the marks as text
        std::string marksText;

        // Separates the record using the | symbol
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Displays the student information
            std::cout << rollText << "\t\t"
                      << name << "\t\t"
                      << marksText << '\n';
        }
    }
}

// Function to search for a student
void searchStudent() {

    // Opens the student record file for reading
    std::ifstream inputFile("student_records.txt");

    // Checks whether the file exists
    if (!inputFile) {

        // Displays message if no file is found
        std::cout << "No student record file found.\n";

        // Exits the function
        return;
    }

    // Stores the roll number to be searched
    int targetRoll;

    // Asks the user to enter roll number
    std::cout << "Enter roll number to search: ";

    // Reads the roll number
    std::cin >> targetRoll;

    // Stores one line from the file
    std::string line;

    // Keeps track of whether the student was found
    bool found = false;

    // Reads the file one line at a time
    while (std::getline(inputFile, line)) {

        // Creates a string stream from the current line
        std::stringstream record(line);

        // Stores roll number as text
        std::string rollText;

        // Stores student name
        std::string name;

        // Stores marks as text
        std::string marksText;

        // Separates the record using the | symbol
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Converts roll number from string to integer and compares it
            if (std::stoi(rollText) == targetRoll) {

                // Displays that the record was found
                std::cout << "Record Found\n";

                // Displays the roll number
                std::cout << "Roll Number: " << rollText << '\n';

                // Displays the student's name
                std::cout << "Name: " << name << '\n';

                // Displays the student's marks
                std::cout << "Marks: " << marksText << '\n';

                // Marks the student as found
                found = true;

                // Stops searching
                break;
            }
        }
    }

    // Checks whether the student was not found
    if (!found) {

        // Displays not found message
        std::cout << "Student not found.\n";
    }
}

// Function to update student marks
void updateMarks() {

    // Opens the original student record file
    std::ifstream inputFile("student_records.txt");

    // Creates a temporary file
    std::ofstream temporaryFile("student_records_temp.txt");

    // Checks whether both files were opened successfully
    if (!inputFile || !temporaryFile) {

        // Displays an error message
        std::cerr << "Error: Could not open record file(s).\n";

        // Exits the function
        return;
    }

    // Stores the roll number to update
    int targetRoll;

    // Stores the new marks
    double newMarks;

    // Asks the user for the roll number
    std::cout << "Enter roll number to update: ";

    // Reads the roll number
    std::cin >> targetRoll;

    // Asks the user for new marks
    std::cout << "Enter new marks: ";

    // Reads the new marks
    std::cin >> newMarks;

    // Stores one line from the file
    std::string line;

    // Keeps track of whether the student was found
    bool found = false;

    // Reads the original file line by line
    while (std::getline(inputFile, line)) {

        // Creates a string stream from the current line
        std::stringstream record(line);

        // Stores roll number as text
        std::string rollText;

        // Stores student name
        std::string name;

        // Stores marks as text
        std::string marksText;

        // Separates the record using the | symbol
        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            // Checks whether the current student is the target student
            if (std::stoi(rollText) == targetRoll) {

                // Writes the updated record to the temporary file
                temporaryFile << rollText << '|'
                              << name << '|'
                              << newMarks << '\n';

                // Marks the student as found
                found = true;

            } else {

                // Copies the unchanged record to the temporary file
                temporaryFile << line << '\n';
            }
        }
    }

    // Closes the original file
    inputFile.close();

    // Closes the temporary file
    temporaryFile.close();

    // Checks whether the student was not found
    if (!found) {

        // Deletes the temporary file
        std::remove("student_records_temp.txt");

        // Displays message that no changes were made
        std::cout << "Student not found. No changes made.\n";

        // Exits the function
        return;
    }

    // Removes the original student record file
    if (std::remove("student_records.txt") != 0 ||

        // Renames the temporary file to the original file name
        std::rename("student_records_temp.txt",
                    "student_records.txt") != 0) {

        // Displays an error message
        std::cerr << "Error: Could not replace the record file.\n";

        // Exits the function
        return;
    }

    // Displays successful update message
    std::cout << "Marks updated successfully.\n";
}

// Main function
int main() {

    // Stores the user's menu choice
    int choice;

    // Repeats the menu until the user chooses 0
    do {

        // Displays the title
        std::cout << "\nStudent Record Manager\n";

        // Displays menu option 1
        std::cout << "1. Add Student\n";

        // Displays menu option 2
        std::cout << "2. Display All Students\n";

        // Displays menu option 3
        std::cout << "3. Search Student\n";

        // Displays menu option 4
        std::cout << "4. Update Marks\n";

        // Displays menu option 0
        std::cout << "0. Exit\n";

        // Asks the user to enter a choice
        std::cout << "Enter choice: ";

        // Reads the user's choice
        std::cin >> choice;

        // Performs an operation according to the choice
        switch (choice) {

            // Option 1: Add student
            case 1:

                // Calls the addStudent function
                addStudent();

                // Stops this case
                break;

            // Option 2: Display all students
            case 2:

                // Calls the displayStudents function
                displayStudents();

                // Stops this case
                break;

            // Option 3: Search student
            case 3:

                // Calls the searchStudent function
                searchStudent();

                // Stops this case
                break;

            // Option 4: Update marks
            case 4:

                // Calls the updateMarks function
                updateMarks();

                // Stops this case
                break;

            // Option 0: Exit
            case 0:

                // Displays exit message
                std::cout << "Exiting program.\n";

                // Stops this case
                break;

            // Handles an invalid choice
            default:

                // Displays invalid choice message
                std::cout << "Invalid choice. Try again.\n";
        }

    // Continues the menu until choice becomes 0
    } while (choice != 0);

    // Returns 0 for successful execution
    return 0;
}