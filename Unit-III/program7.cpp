#include <iostream>                         // Includes the input-output stream library

class Complex {                             // Defines the Complex class

private:                                    // Declares private members
    int real;                               // Stores the real part
    int imaginary;                          // Stores the imaginary part

public:                                     // Declares public members

    // Constructor to initialize real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Declares operator+ as a friend function
    friend Complex operator+(int value, const Complex& number);

    // Function to display the complex number
    void display() const {

        // Displays the real part
        std::cout << real;

        // Checks whether the imaginary part is positive or negative
        if (imaginary >= 0) {

            std::cout << " + ";             // Displays plus sign

        } else {

            std::cout << " - ";             // Displays minus sign
        }

        // Displays the absolute value of the imaginary part followed by i
        std::cout << (imaginary >= 0 ? imaginary : -imaginary)
                  << "i\n";
    }
};                                          // Ends the Complex class


// Defines the friend operator+ function
Complex operator+(int value, const Complex& number) {

    // Adds the integer value to the real part of the Complex object
    // and keeps the imaginary part unchanged
    return Complex(value + number.real, number.imaginary);
}


int main() {                                // Main function where execution starts

    Complex number(2, 3);                    // Creates a Complex object with 2 + 3i

    // Adds integer 10 to the Complex object using the friend operator
    Complex result = 10 + number;

    std::cout << "Result: ";                // Displays result message

    result.display();                       // Displays the resulting complex number

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function