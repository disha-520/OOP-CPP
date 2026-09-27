#include <iostream>                         // Includes the input-output stream library
#include <memory>                           // Includes smart pointer functionality
#include <vector>                           // Includes vector container

class Shape {                               // Defines the abstract Shape class

public:                                     // Declares public members

    // Declares a pure virtual function to calculate area
    virtual double area() const = 0;

    // Declares a pure virtual function to display shape name
    virtual void displayName() const = 0;

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

    // Overrides the area() function
    double area() const override {

        // Calculates and returns the rectangle area
        return length * width;
    }

    // Overrides the displayName() function
    void displayName() const override {

        // Displays the name of the shape
        std::cout << "Rectangle";
    }
};                                          // Ends the Rectangle class


class Circle : public Shape {               // Defines Circle class inheriting from Shape

private:                                    // Declares private members
    double radius;                          // Stores the radius of circle

public:                                     // Declares public members

    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Overrides the area() function
    double area() const override {

        // Defines the constant value of PI
        constexpr double PI = 3.141592653589793;

        // Calculates and returns the circle area
        return PI * radius * radius;
    }

    // Overrides the displayName() function
    void displayName() const override {

        // Displays the name of the shape
        std::cout << "Circle";
    }
};                                          // Ends the Circle class


int main() {                                // Main function where execution starts

    // Creates a vector to store pointers to Shape objects
    std::vector<std::unique_ptr<Shape>> shapes;

    // Creates a Rectangle object and adds it to the vector
    shapes.push_back(
        std::make_unique<Rectangle>(5.0, 3.0)
    );

    // Creates a Circle object and adds it to the vector
    shapes.push_back(
        std::make_unique<Circle>(2.0)
    );

    // Loops through every shape stored in the vector
    for (const auto& shape : shapes) {

        // Displays the name of the current shape
        shape->displayName();

        // Displays the area of the current shape
        std::cout << " Area: "
                  << shape->area()
                  << '\n';
    }

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function