#include <iostream>              // Includes input-output library


// Defines the base class
class Vehicle {

public:                          // Public members of Vehicle

    // Virtual function that can be overridden
    virtual void move() const {

        // Displays the default vehicle movement
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor of Vehicle class
    virtual ~Vehicle() = default;
};                               // Ends Vehicle class


// Car inherits from Vehicle
class Car : public Vehicle {

public:                          // Public members of Car

    // Overrides the move() function of Vehicle
    void move() const override {

        // Displays how a car moves
        std::cout << "Car moves on roads\n";
    }
};                               // Ends Car class


// Boat inherits from Vehicle
class Boat : public Vehicle {

public:                          // Public members of Boat

    // Overrides the move() function of Vehicle
    void move() const override {

        // Displays how a boat moves
        std::cout << "Boat moves on water\n";
    }
};                               // Ends Boat class


// Main function where program execution starts
int main() {

    // Creates a Car object
    Car car;

    // Creates a Boat object
    Boat boat;

    // Calls the overridden move() function of Car
    car.move();

    // Calls the overridden move() function of Boat
    boat.move();

    // Indicates successful program execution
    return 0;
}                               // Ends main function