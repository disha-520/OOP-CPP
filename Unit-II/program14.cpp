#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the outer University class
class University {

public:                          // Public members of University

    // Defines the nested Department class
    class Department {

    private:                     // Private members of Department
        std::string name;        // Stores the department name

    public:                      // Public members of Department

        // Constructor of Department class
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}
            // Initializes the department name

        // Function to display department name
        void display() const {

            // Displays the department name
            std::cout << "Department: " << name << '\n';
        }
    };                           // Ends Department class

};                               // Ends University class


// Main function where program execution starts
int main() {

    // Creates an object of the nested Department class
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Calls the display function
    department.display();

    // Indicates successful program execution
    return 0;
}                               // Ends main function