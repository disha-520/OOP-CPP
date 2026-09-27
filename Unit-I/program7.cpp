// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Define a Student class
class Student {
public:

    // Declare a static integer variable shared by all objects
    static int count;

    // Constructor: automatically called when an object is created
    Student() {

        // Increase the shared count by 1
        count++;
    }
};

// Define and initialize the static variable outside the class
int Student::count = 0;

// Main function: program execution starts here
int main() {

    // Create three Student objects
    Student s1, s2, s3;

    // Display the value of the static count variable
    cout << Student::count;

    // Return 0 to indicate successful program execution
    return 0;
}