#include <iostream>                         // Includes the input-output stream library

class Shape {                               // Defines the Shape base class

public:                                     // Declares public members

    // Defines a virtual function to calculate area
    virtual double area() const {

        // Returns 0 as the default area
        return 0.0;
    }

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

    // Overrides the area() function of Shape
    double area() const override {

        // Calculates and returns the area of rectangle
        return length * width;
    }
};                                          // Ends the Rectangle class


class Circle : public Shape {               // Defines Circle class inheriting from Shape

private:                                    // Declares private members
    double radius;                          // Stores the radius of circle

public:                                     // Declares public members

    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Overrides the area() function of Shape
    double area() const override {

        // Defines the constant value of PI
        constexpr double PI = 3.141592653589793;

        // Calculates and returns the area of circle
        return PI * radius * radius;
    }
};                                          // Ends the Circle class


// Function that accepts any object derived from Shape
void printArea(const Shape& shape) {

    // Calls the appropriate area() function and displays the result
    std::cout << "Area: " << shape.area() << '\n';
}


int main() {                                // Main function where execution starts

    // Creates a Rectangle object with length 5 and width 3
    Rectangle rectangle(5.0, 3.0);

    // Creates a Circle object with radius 2
    Circle circle(2.0);

    // Passes Rectangle object to printArea()
    printArea(rectangle);

    // Passes Circle object to printArea()
    printArea(circle);

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function