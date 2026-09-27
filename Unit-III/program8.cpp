#include <iostream>                         // Includes the input-output stream library

class Base {                                // Defines the Base class

public:                                     // Declares public members

    // Defines the display function in Base class
    void display() const {

        // Displays the Base class message
        std::cout << "Base display function\n";
    }
};                                          // Ends the Base class


class Derived : public Base {               // Defines Derived class inheriting from Base

public:                                     // Declares public members

    // Defines display function again in Derived class
    void display() const {

        // Displays the Derived class message
        std::cout << "Derived display function\n";
    }
};                                          // Ends the Derived class


int main() {                                // Main function where execution starts

    // Creates an object of the Derived class
    Derived derivedObject;

    // Creates a Base class pointer pointing to the Derived object
    Base* basePointer = &derivedObject;

    // Calls display() using the Base class pointer
    basePointer->display();

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function