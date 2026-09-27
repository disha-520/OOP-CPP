// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Main function: program execution starts here
int main() {
    
    // Store the marks of the student
    int marks = 45;

    // Check whether the marks are 40 or above
    if (marks >= 40) {
        
        // Display "Pass" if the condition is true
        cout << "Pass";
        
    } else {
        
        // Display "Fail" if the condition is false
        cout << "Fail";
    }

    // Return 0 to indicate successful program execution
    return 0;
}