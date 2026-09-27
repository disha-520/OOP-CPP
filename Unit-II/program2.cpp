// Include the input-output stream library
#include <iostream>

// Include the string library to use string data type
#include <string>

// Include the utility library for std::move()
#include <utility>

// Define the base class Employee
class Employee {

protected:
    // Protected member: accessible inside Employee
    // and also inside the derived class Developer
    std::string name;

public:
    // Constructor of Employee class
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}
};

// Define Developer class that inherits from Employee
class Developer : public Employee {

private:
    // Private member to store programming language
    std::string language;

public:
    // Constructor of Developer class
    Developer(std::string employeeName, std::string programmingLanguage)

        // Call the constructor of the base class Employee
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {}

    // Function to display developer details
    void display() const {

        // Access the protected name inherited from Employee
        std::cout << "Developer: " << name << '\n';

        // Display the programming language
        std::cout << "Language: " << language << '\n';
    }
};

// Main function: program execution starts here
int main() {

    // Create a Developer object
    // "Neha" is the employee name and "C++" is the language
    Developer developer("Neha", "C++");

    // Call the display function
    developer.display();

    // Return 0 to indicate successful execution
    return 0;
}