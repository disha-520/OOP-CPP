// Include the input-output stream library
#include <iostream>

// Use the standard namespace
using namespace std;

// Define a Student class
class Student {
public:

    // Declare a string variable to store the student's name
    string name;

    // Declare an integer variable to store the student's age
    int age;

    // Define a member function to display student details
    void show() {

        // Display the student's name and age
        cout << name << " " << age << endl;
    }
};

// Main function: program execution starts here
int main() {

    // Create an object s1 of the Student class
    Student s1;

    // Assign a name to the student object
    s1.name = "Amit";

    // Assign an age to the student object
    s1.age = 20;

    // Call the show function to display student details
    s1.show();

    // Return 0 to indicate successful program execution
    return 0;
}