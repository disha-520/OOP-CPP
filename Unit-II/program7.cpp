#include <iostream>              // Includes input-output library


// Defines the Academic base class
class Academic {

public:                          // Public members of Academic

    // Defines the display function
    void display() const {

        // Displays academic information
        std::cout << "Academic information\n";
    }
};                               // Ends Academic class


// Defines the Sports base class
class Sports {

public:                          // Public members of Sports

    // Defines another display function
    void display() const {

        // Displays sports information
        std::cout << "Sports information\n";
    }
};                               // Ends Sports class


// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:                          // Public members of Student

    // Function to display information from both base classes
    void displayAll() const {

        // Calls Academic class display function
        Academic::display();

        // Calls Sports class display function
        Sports::display();
    }
};                               // Ends Student class


// Main function where program execution starts
int main() {

    // Creates an object of Student class
    Student student;

    // Calls Academic's display function using scope-resolution operator
    student.Academic::display();

    // Calls Sports' display function using scope-resolution operator
    student.Sports::display();

    // Calls Student's displayAll function
    student.displayAll();

    // Indicates successful program execution
    return 0;
}                               // Ends main function