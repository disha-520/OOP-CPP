#include <cstring>                    // Includes string handling functions
#include <fstream>                    // Includes file stream library
#include <iostream>                   // Includes input-output library

// Defines a structure for storing student records
struct StudentRecord {

    int rollNumber;                   // Stores the student's roll number

    char name[30];                    // Stores the student's name

    float marks;                      // Stores the student's marks
};

// Function to add a student record to the binary file
void addRecord(std::ofstream& file, int rollNumber, const char* name, float marks) {

    // Creates a StudentRecord object and initializes its members
    StudentRecord student{};

    // Assigns the roll number
    student.rollNumber = rollNumber;

    // Copies the student's name into the character array
    std::strncpy(student.name, name, sizeof(student.name) - 1);

    // Assigns the student's marks
    student.marks = marks;

    // Writes the student record as raw binary data
    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
}

int main() {                          // Main function where program execution starts

    // Creates a block for writing records into the binary file
    {
        // Opens records.dat in binary and truncate mode
        std::ofstream outputFile(
            "records.dat",
            std::ios::binary | std::ios::trunc
        );

        // Checks whether the file was created successfully
        if (!outputFile) {

            // Displays an error message
            std::cerr << "Error: Could not create records.dat\n";

            // Returns 1 to indicate an error
            return 1;
        }

        // Adds the first student record
        addRecord(outputFile, 101, "Amit", 85.5F);

        // Adds the second student record
        addRecord(outputFile, 102, "Neha", 91.0F);

        // Adds the third student record
        addRecord(outputFile, 103, "Ravi", 78.0F);
    } // Automatically closes the output file here

    // Opens records.dat in binary reading mode
    std::ifstream inputFile("records.dat", std::ios::binary);

    // Checks whether the file was opened successfully
    if (!inputFile) {

        // Displays an error message
        std::cerr << "Error: Could not open records.dat\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Stores the record number entered by the user
    int recordNumber;

    // Asks the user to enter a record number
    std::cout << "Enter record number to read (1 to 3): ";

    // Reads the record number
    std::cin >> recordNumber;

    // Checks whether the entered record number is valid
    if (recordNumber < 1 || recordNumber > 3) {

        // Displays an error message
        std::cerr << "Invalid record number.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Calculates the position of the selected record
    const std::streamoff offset =
        static_cast<std::streamoff>(recordNumber - 1) *
        static_cast<std::streamoff>(sizeof(StudentRecord));

    // Moves the input pointer to the selected record
    inputFile.seekg(offset, std::ios::beg);

    // Creates an empty object to store the selected student record
    StudentRecord selectedStudent{};

    // Reads the selected student record from the binary file
    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );

    // Checks whether the selected record was read successfully
    if (!inputFile) {

        // Displays an error message
        std::cerr << "Error: Could not read selected record.\n";

        // Returns 1 to indicate an error
        return 1;
    }

    // Displays the selected student's roll number
    std::cout << "Roll Number: " << selectedStudent.rollNumber << '\n';

    // Displays the selected student's name
    std::cout << "Name: " << selectedStudent.name << '\n';

    // Displays the selected student's marks
    std::cout << "Marks: " << selectedStudent.marks << '\n';

    // Returns 0 to indicate successful program execution
    return 0;
}