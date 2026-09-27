#include <iostream>                         // Includes the input-output stream library

class Complex {                             // Defines the Complex class

private:                                    // Declares private members
    int real;                               // Stores the real part
    int imaginary;                          // Stores the imaginary part

public:                                     // Declares public members

    // Constructor to initialize real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overloads the binary addition (+) operator
    Complex operator+(const Complex& other) const {

        // Returns a new Complex object containing the sum
        return Complex(real + other.real,
                       imaginary + other.imaginary);
    }

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

int main() {                                // Main function where execution starts

    Complex first(2, 3);                    // Creates first complex number

    Complex second(4, 5);                   // Creates second complex number

    Complex sum = first + second;            // Adds two complex numbers using overloaded +

    std::cout << "First complex number: ";  // Displays first number message

    first.display();                        // Displays the first complex number

    std::cout << "Second complex number: "; // Displays second number message

    second.display();                       // Displays the second complex number

    std::cout << "Sum: ";                   // Displays sum message

    sum.display();                          // Displays the resulting complex number

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function