#include <iostream>                         // Includes the input-output stream library
#include <string>                           // Includes the string library
#include <utility>                          // Includes std::move()

class Employee {                            // Defines the Employee class

protected:                                  // Declares protected members
    int employeeId;                         // Stores the employee ID
    std::string name;                       // Stores the employee name

public:                                     // Declares public members

    // Constructor to initialize employee ID and name
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Declares a pure virtual function to calculate salary
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

    // Defines a virtual destructor
    virtual ~Employee() = default;
};                                          // Ends the Employee class


class PermanentEmployee : public Employee { // Defines PermanentEmployee class

private:                                    // Declares private members
    double basicSalary;                     // Stores the basic salary
    double allowance;                       // Stores the allowance

public:                                     // Declares public members

    // Constructor to initialize permanent employee details
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {}

    // Overrides the calculateSalary() function
    double calculateSalary() const override {

        // Returns basic salary plus allowance
        return basicSalary + allowance;
    }
};                                          // Ends the PermanentEmployee class


class ContractEmployee : public Employee {  // Defines ContractEmployee class

private:                                    // Declares private members
    double hourlyRate;                      // Stores hourly payment rate
    int hoursWorked;                        // Stores number of hours worked

public:                                     // Declares public members

    // Constructor to initialize contract employee details
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}

    // Overrides the calculateSalary() function
    double calculateSalary() const override {

        // Calculates salary using hourly rate and hours worked
        return hourlyRate * hoursWorked;
    }
};                                          // Ends the ContractEmployee class


// Function to print the employee pay slip
void printPaySlip(const Employee& employee) {

    // Displays basic employee details
    employee.displayBasicDetails();

    // Calculates and displays the employee salary
    std::cout << "Salary: Rs. "
              << employee.calculateSalary()
              << "\n\n";
}


int main() {                                // Main function where execution starts

    // Creates a PermanentEmployee object
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Creates a ContractEmployee object
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Prints the pay slip of the permanent employee
    printPaySlip(permanentEmployee);

    // Prints the pay slip of the contract employee
    printPaySlip(contractEmployee);

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function