#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the base class
class Person {

protected:                       // Accessible inside Person and derived classes
    std::string name;            // Stores the person's name

public:                          // Public members of Person

    // Parameterized constructor of Person
    explicit Person(std::string personName)
        : name(std::move(personName)) {}  // Initializes the name
};                               // Ends Person class


// Student inherits from Person
class Student : public Person {

private:                         // Private members of Student
    int rollNumber;              // Stores roll number

public:                          // Public members of Student

    // Constructor of Student
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}
        // Calls the parameterized constructor of Person
        // and initializes rollNumber

    // Function to display student details
    void display() const {

        // Displays the inherited name
        std::cout << "Name: " << name << '\n';

        // Displays the student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};                               // Ends Student class


// Main function where program execution starts
int main() {

    // Creates a Student object
    Student student("Kiran", 24);

    // Calls the display function
    student.display();

    // Indicates successful program execution
    return 0;
}                               // Ends main function