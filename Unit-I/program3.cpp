// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Main function: program execution starts here
int main() {
    
    // Declare an integer array of 5 elements and initialize it with marks
    int marks[5] = {78, 82, 91, 67, 88};

    // Loop through all 5 elements of the array
    for (int i = 0; i < 5; i++) {
        
        // Display each mark followed by a space
        cout << marks[i] << " ";
    }

    // Return 0 to indicate successful program execution
    return 0;
}