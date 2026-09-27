#include <iostream>              // Includes input-output library
#include <string>                // Includes string data type
#include <utility>               // Includes std::move()

// Defines the base class Vehicle
class Vehicle {

protected:                       // Accessible inside Vehicle and derived classes
    std::string registrationNumber;  // Stores vehicle registration number

public:                          // Public members of Vehicle

    // Constructor of Vehicle class
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}  // Initializes registration number

    // Function to start the vehicle
    void start() const {
        // Displays vehicle registration number and start message
        std::cout << "Vehicle " << registrationNumber << " started\n";
    }
};                               // Ends Vehicle class


// Car inherits from Vehicle
class Car : public Vehicle {

public:                          // Public members of Car

    // Constructor of Car class
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {}  // Calls Vehicle constructor

    // Function to open the car boot
    void openBoot() const {
        std::cout << "Car boot opened\n";  // Displays boot message
    }
};                               // Ends Car class


// Bike inherits from Vehicle
class Bike : public Vehicle {

public:                          // Public members of Bike

    // Constructor of Bike class
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {}  // Calls Vehicle constructor

    // Function to remind the rider about helmet
    void helmetReminder() const {
        std::cout << "Please wear a helmet\n";  // Displays helmet reminder
    }
};                               // Ends Bike class


// Main function where program execution starts
int main() {

    // Creates a Car object
    Car car("MH12AB1234");

    // Creates a Bike object
    Bike bike("MH12CD5678");

    // Calls start function inherited from Vehicle
    car.start();

    // Calls Car's own function
    car.openBoot();

    // Calls start function inherited from Vehicle
    bike.start();

    // Calls Bike's own function
    bike.helmetReminder();

    // Indicates successful program execution
    return 0;
}                               // Ends main function