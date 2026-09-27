// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Function declaration: tells the compiler about the add function
int add(int, int);

// Main function: program execution starts here
int main() {

    // Declare and initialize two integer variables
    int a = 10, b = 20;

    // Call the add function and display the returned sum
    cout << "Sum = " << add(a, b) << endl;

    // Return 0 to indicate successful program execution
    return 0;
}

// Function definition: adds two numbers and returns their sum
int add(int x, int y) {
    
    // Return the addition of x and y
    return x + y;
}