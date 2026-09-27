#include <iostream>                 // Includes the input-output stream library

int calculateArea(int side) {      // Defines function to calculate square area
    return side * side;             // Returns side multiplied by side
}

int calculateArea(int length, int width) { // Defines function to calculate rectangle area
    return length * width;                 // Returns length multiplied by width
}

double calculateArea(double radius) {      // Defines function to calculate circle area
    constexpr double PI = 3.141592653589793; // Defines constant value of PI
    return PI * radius * radius;            // Calculates and returns circle area
}

int main() {                            // Main function where program execution starts

    std::cout << "Square Area: "       // Displays square area message
              << calculateArea(5)      // Calls calculateArea() for square
              << '\n';                 // Moves to the next line

    std::cout << "Rectangle Area: "    // Displays rectangle area message
              << calculateArea(6, 4)   // Calls calculateArea() for rectangle
              << '\n';                 // Moves to the next line

    std::cout << "Circle Area: "       // Displays circle area message
              << calculateArea(2.0)    // Calls calculateArea() for circle
              << '\n';                 // Moves to the next line

    return 0;                          // Returns 0 for successful execution
}                                      // Ends the main() function