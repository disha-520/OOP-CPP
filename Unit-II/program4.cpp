#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the first/base class
class Person {

protected:                       // Accessible inside this class and derived classes
    std::string name;            // Stores the person's name

public:                          // Public members can be accessed from outside

    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}   // Initializes name
     
    // Function to display person's name
    void showPerson() const {
        std::cout << "Name: " << name << '\n';  // Displays the name
    }
};                               // Ends Person class


// Employee inherits from Person
class Employee : public Person {

protected:                       // Accessible in Employee and further derived classes
    int employeeId;              // Stores employee ID

public:                          // Public members of Employee

    // Constructor of Employee class
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {}  // Initializes base and ID

    // Function to display employee ID
    void showEmployee() const {
        std::cout << "Employee ID: " << employeeId << '\n';  // Displays employee ID
    }
};                               // Ends Employee class


// Manager inherits from Employee
class Manager : public Employee {

private:                         // Accessible only inside Manager class
    int teamSize;                // Stores team size

public:                          // Public members of Manager

    // Constructor of Manager class
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {}  // Initializes Employee and team size

    // Function to display manager details
    void showManager() const {

        showPerson();            // Calls function inherited from Person

        showEmployee();          // Calls function inherited from Employee

        std::cout << "Team Size: " << teamSize << '\n';  // Displays team size
    }
};                               // Ends Manager class


// Main function where program execution starts
int main() {

    // Creates an object of Manager class
    Manager manager("Ravi", 501, 8);

    // Calls function to display all manager details
    manager.showManager();

    // Indicates successful program execution
    return 0;
}                               // Ends main function