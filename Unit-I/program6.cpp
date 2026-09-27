// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Define a Demo class
class Demo {
public:

    // Constructor: automatically called when an object is created
    Demo() {
        cout << "Constructor called\n";
    }

    // Destructor: automatically called when an object is destroyed
    ~Demo() {
        cout << "Destructor called\n";
    }
};

// Main function: program execution starts here
int main() {

    // Create an object d of the Demo class
    // This automatically calls the constructor
    Demo d;

    // Return 0 to indicate successful program execution
    // After this, the object d is destroyed and the destructor is called
    return 0;
}