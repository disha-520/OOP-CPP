#include <iostream>              // Includes the input-output stream library

using namespace std;             // Allows us to use cout without writing std::

// Defines the base class
class Base {

public:                          // Makes the following members accessible from outside

    // Defines a public function named show
    void show() const {

        // Displays a message on the screen
        cout << "Base public function" << endl;
    }                                // Ends the show() function
};                                   // Ends the Base class


// Defines a derived class using public inheritance
class PublicDerived : public Base {
    
    // Public members of Base remain public in PublicDerived
};                                   // Ends the PublicDerived class


// Defines another derived class using private inheritance
class PrivateDerived : private Base {

public:                              // Makes the following function accessible from outside

    // Defines a function to call the Base class show() function
    void callBaseShow() const {

        // Calls the inherited show() function
        show();
    }                               // Ends the callBaseShow() function
};                                  // Ends the PrivateDerived class


// Main function where program execution starts
int main() {

    // Creates an object of PublicDerived class
    PublicDerived publicObject;

    // Calls the public show() function through the object
    publicObject.show();

    // Creates an object of PrivateDerived class
    PrivateDerived privateObject;

    // Calls callBaseShow() to access the Base class show() function
    privateObject.callBaseShow();

    // The following statement would cause an error:
    // privateObject.show();

    // Because show() becomes private through private inheritance

    // Returns 0 to indicate successful program execution
    return 0;
}                                   // Ends the main() function