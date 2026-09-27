#include <iostream>              // Includes input-output library


// Defines the base class
class Base {

public:                          // Public members of Base

    // Constructor of Base class
    Base() {

        // Displays message when Base constructor runs
        std::cout << "Base constructor\n";
    }

    // Destructor of Base class
    ~Base() {

        // Displays message when Base destructor runs
        std::cout << "Base destructor\n";
    }
};                               // Ends Base class


// Defines the derived class
class Derived : public Base {

public:                          // Public members of Derived

    // Constructor of Derived class
    Derived() {

        // Displays message when Derived constructor runs
        std::cout << "Derived constructor\n";
    }

    // Destructor of Derived class
    ~Derived() {

        // Displays message when Derived destructor runs
        std::cout << "Derived destructor\n";
    }
};                               // Ends Derived class


// Main function where program execution starts
int main() {

    // Creates an object of Derived class
    Derived object;

    // Indicates successful program execution
    return 0;
}                               // Object is destroyed here