// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Define a Test class
class Test {
private:

    // Private variable to store a value
    int value;

public:

    // Parameterized constructor
    Test(int v) {
        value = v;
    }

    // Inline function to return the private value
    inline int getValue() {
        return value;
    }

    // Declare show() as a friend function
    // It can access the private members of Test
    friend void show(Test t);
};

// Define the friend function
void show(Test t) {

    // Access and display the private value
    cout << t.value;
}

// Main function: program execution starts here
int main() {

    // Create a Test object and pass 50 to the constructor
    Test obj(50);

    // Call the inline function and display the value
    cout << obj.getValue() << endl;

    // Call the friend function
    show(obj);

    // Return 0 to indicate successful program execution
    return 0;
}