#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the abstract Employee class
class Employee {

protected:                       // Accessible in Employee and derived classes
    int employeeId;              // Stores employee ID
    std::string name;            // Stores employee name

public:                          // Public members of Employee

    // Constructor of Employee class
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}
        // Initializes employee ID and name

    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Function to display basic employee details
    void displayBasicDetails() const {

        // Displays employee ID
        std::cout << "Employee ID: "
                  << employeeId << '\n';

        // Displays employee name
        std::cout << "Name: "
                  << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;

};                               // Ends Employee class


// PermanentEmployee inherits from Employee
class PermanentEmployee : public Employee {

private:                         // Private members of PermanentEmployee
    double basicSalary;           // Stores basic salary
    double allowance;             // Stores allowance

public:                          // Public members of PermanentEmployee

    // Constructor of PermanentEmployee
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {}
        // Initializes Employee, basic salary and allowance

    // Overrides the calculateSalary function
    double calculateSalary() const override {

        // Returns total salary
        return basicSalary + allowance;
    }

};                               // Ends PermanentEmployee class


// ContractEmployee inherits from Employee
class ContractEmployee : public Employee {

private:                         // Private members of ContractEmployee
    double hourlyRate;            // Stores hourly payment rate
    int hoursWorked;              // Stores hours worked

public:                          // Public members of ContractEmployee

    // Constructor of ContractEmployee
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}
        // Initializes Employee, hourly rate and hours worked

    // Overrides the calculateSalary function
    double calculateSalary() const override {

        // Calculates salary using hourly rate and hours
        return hourlyRate * hoursWorked;
    }

};                               // Ends ContractEmployee class


// Function to display an employee's pay slip
void displayPaySlip(const Employee& employee) {

    // Displays basic employee details
    employee.displayBasicDetails();

    // Calculates and displays salary
    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
}


// Main function where program execution starts
int main() {

    // Creates a PermanentEmployee object
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Creates a ContractEmployee object
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Displays permanent employee pay slip
    displayPaySlip(permanentEmployee);

    // Displays contract employee pay slip
    displayPaySlip(contractEmployee);

    // Indicates successful program execution
    return 0;
}                               // Ends main function