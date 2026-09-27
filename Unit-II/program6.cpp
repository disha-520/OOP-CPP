#include <iostream>              // Includes input-output library


// Defines the Academic base class
class Academic {

protected:                       // Accessible inside this class and derived classes
    int academicMarks;           // Stores academic marks

public:                          // Public members of Academic

    // Constructor of Academic class
    explicit Academic(int marks)
        : academicMarks(marks) {}    // Initializes academic marks

    // Function to display academic marks
    void showAcademic() const {
        // Displays academic marks
        std::cout << "Academic Marks: " << academicMarks << '\n';
    }
};                               // Ends Academic class


// Defines the Sports base class
class Sports {

protected:                       // Accessible inside this class and derived classes
    int sportsMarks;             // Stores sports marks

public:                          // Public members of Sports

    // Constructor of Sports class
    explicit Sports(int marks)
        : sportsMarks(marks) {}  // Initializes sports marks

    // Function to display sports marks
    void showSports() const {
        // Displays sports marks
        std::cout << "Sports Marks: " << sportsMarks << '\n';
    }
};                               // Ends Sports class


// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:                          // Public members of Student

    // Constructor of Student class
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {}  // Initializes both base classes

    // Function to calculate and display total marks
    void showTotal() const {

        // Adds academic and sports marks
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks << '\n';
    }
};                               // Ends Student class


// Main function where program execution starts
int main() {

    // Creates a Student object with academic marks 80 and sports marks 15
    Student student(80, 15);

    // Calls function inherited from Academic
    student.showAcademic();

    // Calls function inherited from Sports
    student.showSports();

    // Calls Student's function to display total marks
    student.showTotal();

    // Indicates successful program execution
    return 0;
}                               // Ends main function