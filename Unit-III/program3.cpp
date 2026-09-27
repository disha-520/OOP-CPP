#include <iostream>                         // Includes the input-output stream library

class Number {                              // Defines the Number class

private:                                    // Declares private members
    int value;                              // Stores the number value

public:                                     // Declares public members

    // Constructor to initialize the value
    explicit Number(int givenValue)
        : value(givenValue) {}

    // Overloads the unary minus (-) operator
    Number operator-() const {

        // Creates and returns a Number object with negative value
        return Number(-value);
    }

    // Function to display the value
    void display() const {

        // Displays the stored value
        std::cout << value << '\n';
    }
};                                          // Ends the Number class

int main() {                                // Main function where execution starts

    Number first(25);                       // Creates first object with value 25

    Number second = -first;                 // Applies unary minus operator to first

    std::cout << "Original value: ";        // Displays original value message

    first.display();                        // Displays the original value

    std::cout << "Negated value: ";         // Displays negated value message

    second.display();                       // Displays the negated value

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function