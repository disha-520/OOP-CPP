// Include the input-output stream library
#include <iostream>

// Include the string library to use string data type
#include <string>

// Include the utility library for std::move()
#include <utility>

// Define the base class Person
class Person {

protected:
    // Protected member: accessible inside Person and derived classes
    std::string name;

public:
    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display the person's name
    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Define Student class that inherits from Person
class Student : public Person {

private:
    // Private member to store the student's roll number
    int rollNumber;

public:
    // Constructor of Student class
    Student(std::string studentName, int roll)

        // Call the constructor of the base class Person
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Function to display student details
    void displayStudent() const {

        // Call the displayName() function of the Person class
        displayName();

        // Display the student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function: program execution starts here
int main() {

    // Create a Student object
    // "Amit" is the name and 101 is the roll number
    Student student("Amit", 101);

    // Call the function to display student details
    student.displayStudent();

    // Return 0 to indicate successful execution
    return 0;
}
