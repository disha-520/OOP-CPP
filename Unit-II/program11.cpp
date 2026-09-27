#include <iostream>              // Includes input-output library


// Defines the abstract base class
class Shape {

public:                          // Public members of Shape

    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;

};                               // Ends Shape class


// Rectangle inherits from Shape
class Rectangle : public Shape {

private:                         // Private members of Rectangle
    double length;               // Stores length of rectangle
    double width;                // Stores width of rectangle

public:                          // Public members of Rectangle

    // Constructor of Rectangle
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}
        // Initializes length and width

    // Overrides the pure virtual area() function
    double area() const override {

        // Returns area of rectangle
        return length * width;
    }

};                               // Ends Rectangle class


// Circle inherits from Shape
class Circle : public Shape {

private:                         // Private members of Circle
    double radius;               // Stores radius of circle

public:                          // Public members of Circle

    // Constructor of Circle
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}
        // Initializes radius

    // Overrides the pure virtual area() function
    double area() const override {

        // Calculates and returns area of circle
        return 3.141592653589793 * radius * radius;
    }

};                               // Ends Circle class


// Main function where program execution starts
int main() {

    // Creates a Rectangle object with length 5 and width 3
    Rectangle rectangle(5.0, 3.0);

    // Creates a Circle object with radius 2
    Circle circle(2.0);

    // Displays the area of rectangle
    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n';

    // Displays the area of circle
    std::cout << "Circle Area: "
              << circle.area() << '\n';

    // Indicates successful program execution
    return 0;

}                               // Ends main function