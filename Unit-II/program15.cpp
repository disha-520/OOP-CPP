#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the base Vehicle class
class Vehicle {

protected:                       // Accessible in Vehicle and derived classes
    std::string registrationNumber; // Stores registration number
    double ratePerDay;            // Stores rental rate per day

public:                          // Public members of Vehicle

    // Constructor of Vehicle class
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}
        // Initializes registration number and daily rate

    // Virtual function to calculate rent
    virtual double calculateRent(int days) const {

        // Calculates rent using number of days
        return ratePerDay * days;
    }

    // Virtual function to display vehicle details
    virtual void display() const {

        // Displays registration number
        std::cout << "Registration: "
                  << registrationNumber << '\n';

        // Displays rate per day
        std::cout << "Rate per day: "
                  << ratePerDay << '\n';
    }

    // Virtual destructor
    virtual ~Vehicle() = default;

};                               // Ends Vehicle class


// Car inherits from Vehicle
class Car : public Vehicle {

private:                         // Private members of Car
    int numberOfDoors;            // Stores number of doors

public:                          // Public members of Car

    // Constructor of Car class
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors) {}
        // Initializes Vehicle and number of doors

    // Overrides the display function
    void display() const override {

        // Calls display function of Vehicle
        Vehicle::display();

        // Displays number of doors
        std::cout << "Doors: "
                  << numberOfDoors << '\n';
    }
};                               // Ends Car class


// Bike inherits from Vehicle
class Bike : public Vehicle {

private:                         // Private members of Bike
    int engineCapacity;           // Stores engine capacity

public:                          // Public members of Bike

    // Constructor of Bike class
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {}
        // Initializes Vehicle and engine capacity

    // Overrides the calculateRent function
    double calculateRent(int days) const override {

        // Calculates bike rent with 10% discount
        return ratePerDay * days * 0.9;
    }

    // Overrides the display function
    void display() const override {

        // Calls display function of Vehicle
        Vehicle::display();

        // Displays engine capacity
        std::cout << "Engine Capacity: "
                  << engineCapacity << " cc\n";
    }
};                               // Ends Bike class


// Main function where program execution starts
int main() {

    // Creates a Car object
    Car car("MH12AB1234", 2000.0, 5);

    // Creates a Bike object
    Bike bike("MH12CD5678", 800.0, 150);

    // Displays Car heading
    std::cout << "Car Details\n";

    // Displays Car details
    car.display();

    // Calculates and displays Car rent for 3 days
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3) << "\n\n";

    // Displays Bike heading
    std::cout << "Bike Details\n";

    // Displays Bike details
    bike.display();

    // Calculates and displays Bike rent for 3 days
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3) << '\n';

    // Indicates successful program execution
    return 0;
}                               // Ends main functions