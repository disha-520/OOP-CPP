#include <iostream>                         // Includes the input-output stream library

class Distance {                            // Defines the Distance class

private:                                    // Declares private members
    int meters;                             // Stores distance in meters

public:                                     // Declares public members

    // Constructor to initialize the distance
    explicit Distance(int value)
        : meters(value) {}

    // Overloads the greater-than (>) operator
    bool operator>(const Distance& other) const {

        // Compares the meters of two Distance objects
        return meters > other.meters;
    }

    // Function to display the distance
    void display() const {

        // Displays the distance in meters
        std::cout << meters << " meters\n";
    }
};                                          // Ends the Distance class

int main() {                                // Main function where execution starts

    Distance first(120);                    // Creates first Distance object with 120 meters

    Distance second(90);                    // Creates second Distance object with 90 meters

    std::cout << "First distance: ";        // Displays first distance message

    first.display();                        // Displays the first distance

    std::cout << "Second distance: ";       // Displays second distance message

    second.display();                       // Displays the second distance

    // Checks whether the first distance is greater than the second
    if (first > second) {

        std::cout << "First distance is greater\n"; // Displays result if first is greater

    } else {

        // Displays result if first is not greater
        std::cout << "Second distance is greater or equal\n";
    }

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function