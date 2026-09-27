#include <iostream>                         // Includes the input-output stream library

class Shape {                               // Defines the abstract Shape class

public:                                     // Declares public members

    // Declares a pure virtual function for calculating area
    virtual double area() const = 0;

    // Defines a virtual destructor
    virtual ~Shape() = default;
};                                          // Ends the Shape class


class Rectangle : public Shape {            // Defines Rectangle class inheriting from Shape

private:                                    // Declares private members
    double length;                          // Stores the length of rectangle
    double width;                           // Stores the width of rectangle

public:                                     // Declares public members

    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overrides the pure virtual area() function
    double area() const override {

        // Calculates and returns the area of rectangle
        return length * width;
    }
};                                          // Ends the Rectangle class


int main() {                                // Main function where execution starts

    // Creates a Rectangle object with length 8 and width 4
    Rectangle rectangle(8.0, 4.0);

    // Calculates and displays the rectangle area
    std::cout << "Rectangle Area: "
              << rectangle.area()
              << '\n';

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function