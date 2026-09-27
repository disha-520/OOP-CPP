#include <iostream>                         // Includes the input-output stream library

class Base {                                // Defines the Base class

public:                                     // Declares public members

    // Defines a virtual destructor for the Base class
    virtual ~Base() {

        // Displays the Base destructor message
        std::cout << "Base destructor\n";
    }
};                                          // Ends the Base class


class Derived : public Base {               // Defines Derived class inheriting from Base

public:                                     // Declares public members

    // Defines the Derived destructor and overrides Base destructor
    ~Derived() override {

        // Displays the Derived destructor message
        std::cout << "Derived destructor\n";
    }
};                                          // Ends the Derived class


int main() {                                // Main function where execution starts

    // Creates a Derived object dynamically and stores its address in Base pointer
    Base* pointer = new Derived();

    // Deletes the object through the Base pointer
    delete pointer;

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function