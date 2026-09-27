#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the base class Person
class Person {

protected:                       // Accessible in Person and derived classes
    std::string name;            // Stores the person's name

public:                          // Public members of Person

    // Parameterized constructor of Person
    explicit Person(std::string personName)
        : name(std::move(personName)) {}  // Initializes name

    // Function to display person's name
    void displayName() const {

        // Displays the person's name
        std::cout << "Name: " << name << '\n';
    }
};                               // Ends Person class


// Student virtually inherits from Person
class Student : virtual public Person {

public:                          // Public members of Student

    // Constructor of Student
    Student()
        : Person("Unknown") {}   // Initializes the virtual base class
};                               // Ends Student class


// Employee virtually inherits from Person
class Employee : virtual public Person {

public:                          // Public members of Employee

    // Constructor of Employee
    Employee()
        : Person("Unknown") {}   // Initializes the virtual base class
};                               // Ends Employee class


// TeachingAssistant inherits from Student and Employee
class TeachingAssistant : public Student, public Employee {

public:                          // Public members of TeachingAssistant

    // Constructor of TeachingAssistant
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)), // Initializes the shared Person
          Student(),                        // Calls Student constructor
          Employee() {}                     // Calls Employee constructor
};                               // Ends TeachingAssistant class


// Main function where program execution starts
int main() {

    // Creates a TeachingAssistant object
    TeachingAssistant assistant("Riya");

    // Calls the displayName function inherited from Person
    assistant.displayName();

    // Indicates successful program execution
    return 0;
}                               // Ends main functions