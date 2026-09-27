#include <iostream>                         // Includes the input-output stream library

class Base {                                // Defines the Base class

public:                                     // Declares public members

    // Defines a virtual display function
    virtual void display() const {

        // Displays the Base object message
        std::cout << "Base object\n";
    }

    // Defines a virtual destructor
    virtual ~Base() = default;
};                                          // Ends the Base class


class Derived : public Base {               // Defines Derived class inheriting from Base

public:                                     // Declares public members

    // Overrides the display function of Base
    void display() const override {

        // Displays the Derived object message
        std::cout << "Derived object\n";
    }
};                                          // Ends the Derived class


// Function that receives a Base object by value
void displayByValue(Base object) {

    // Calls the display function of the copied Base object
    object.display();
}


// Function that receives a Base object by reference
void displayByReference(const Base& object) {

    // Calls the display function through the Base reference
    object.display();
}


int main() {                                // Main function where execution starts

    // Creates an object of the Derived class
    Derived derived;

    // Displays the passing-by-value message
    std::cout << "Passing by value: ";

    // Passes the Derived object by value
    displayByValue(derived);

    // Displays the passing-by-reference message
    std::cout << "Passing by reference: ";

    // Passes the Derived object by reference
    displayByReference(derived);

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function