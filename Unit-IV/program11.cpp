#include <cstring>                    // Includes string handling functions
#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library

// Defines a structure for storing student records
struct StudentRecord {

    int rollNumber;                   // Stores the student's roll number

    char name[30];                    // Stores the student's name

    float marks;                      // Stores the student's marks
};

int main() {                          // Main function where program execution starts

    // Creates a StudentRecord object and initializes all members to zero
    StudentRecord student{};

    // Assigns the roll number
    student.rollNumber = 101;

    // Copies the student's name into the character array
    std::strncpy(student.name, "Amit Patil", sizeof(student.name) - 1);

    // Assigns the student's marks
    student.marks = 85.5F;

    // Creates a block for writing the binary file
    {
        // Opens students.dat in binary writing mode
        std::ofstream outputFile("students.dat", std::ios::binary);

        // Checks whether the file was created successfully
        if (!outputFile) {

            // Displays an error message
            std::cerr << "Error: Could not create students.dat\n";

            // Returns 1 to indicate an error
            return 1;
        }

        // Writes the student record as raw binary data
        outputFile.write(
            reinterpret_cast<const char*>(&student),
            sizeof(student)
        );

    } // Automatically closes the output file here

    // Creates an empty StudentRecord object for reading
    StudentRecord readStudent{};

    // Creates a block for reading the binary file
    {
        // Opens students.dat in binary reading mode
        std::ifstream inputFile("students.dat", std::ios::binary);

        // Checks whether the file was opened successfully
        if (!inputFile) {

            // Displays an error message
            std::cerr << "Error: Could not open students.dat\n";

            // Returns 1 to indicate an error
            return 1;
        }

        // Reads the binary student record from the file
        inputFile.read(
            reinterpret_cast<char*>(&readStudent),
            sizeof(readStudent)
        );

        // Checks whether the record was read successfully
        if (!inputFile) {

            // Displays an error message
            std::cerr << "Error: Could not read record from students.dat\n";

            // Returns 1 to indicate an error
            return 1;
        }

    } // Automatically closes the input file here

    // Displays the student's roll number
    std::cout << "Roll Number: " << readStudent.rollNumber << '\n';

    // Displays the student's name
    std::cout << "Name: " << readStudent.name << '\n';

    // Displays the student's marks
    std::cout << "Marks: " << readStudent.marks << '\n';

    // Returns 0 to indicate successful program execution
    return 0;
}