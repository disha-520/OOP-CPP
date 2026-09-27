#include <fstream>                 // Includes file handling library
#include <iostream>                // Includes input-output library
#include <limits>                  // Includes numeric limits
#include <sstream>                 // Includes string stream library
#include <string>                  // Includes string library

// Defines a class named Book
class Book {

private:

    int bookId;                    // Stores the book ID
    std::string title;             // Stores the book title
    std::string author;            // Stores the author's name
    bool issued;                   // Stores the book issue status

public:

    // Constructor to initialize book details
    Book(int id, std::string bookTitle, std::string bookAuthor, bool issueStatus = false)

        // Initializes book ID, title, author and issue status
        : bookId(id), title(std::move(bookTitle)),
          author(std::move(bookAuthor)), issued(issueStatus) {}

    // Function to return the book ID
    int getBookId() const {
        return bookId;             // Returns the book ID
    }

    // Converts book details into a text record
    std::string toFileRecord() const {

        // Creates a record using | as a separator
        return std::to_string(bookId) + "|" + title + "|" +
               author + "|" + (issued ? "1" : "0");
    }

    // Function to display book details
    void display() const {

        // Displays the book ID
        std::cout << "Book ID: " << bookId << '\n';

        // Displays the book title
        std::cout << "Title: " << title << '\n';

        // Displays the author name
        std::cout << "Author: " << author << '\n';

        // Displays whether the book is issued or available
        std::cout << "Status: "
                  << (issued ? "Issued" : "Available") << '\n';
    }
};

// Function to add a new book
void addBook() {

    int id;                        // Stores the book ID
    std::string title;             // Stores the book title
    std::string author;            // Stores the author name

    // Asks the user to enter book ID
    std::cout << "Enter book ID: ";

    // Reads the book ID
    std::cin >> id;

    // Removes the remaining newline from the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Asks the user to enter title
    std::cout << "Enter title: ";

    // Reads the complete book title
    std::getline(std::cin, title);

    // Asks the user to enter author
    std::cout << "Enter author: ";

    // Reads the complete author name
    std::getline(std::cin, author);

    // Creates a Book object
    Book book(id, title, author);

    // Opens the library file in append mode
    std::ofstream outputFile("library_books.txt", std::ios::app);

    // Checks whether the file opened successfully
    if (!outputFile) {

        // Displays an error message
        std::cerr << "Error: Could not open library_books.txt\n";

        // Exits the function
        return;
    }

    // Writes the book record into the file
    outputFile << book.toFileRecord() << '\n';

    // Displays success message
    std::cout << "Book added successfully.\n";
}

// Function to display all books
void displayBooks() {

    // Opens the library file for reading
    std::ifstream inputFile("library_books.txt");

    // Checks whether the file exists
    if (!inputFile) {

        // Displays message if no file is found
        std::cout << "No library record file found.\n";

        // Exits the function
        return;
    }

    // Stores one line from the file
    std::string line;

    // Reads the file one line at a time
    while (std::getline(inputFile, line)) {

        // Creates a string stream from the current line
        std::stringstream record(line);

        // Stores book ID as text
        std::string idText;

        // Stores book title
        std::string title;

        // Stores author name
        std::string author;

        // Stores issue status as text
        std::string issuedText;

        // Separates the record using the | symbol
        if (std::getline(record, idText, '|') &&
            std::getline(record, title, '|') &&
            std::getline(record, author, '|') &&
            std::getline(record, issuedText)) {

            // Creates a Book object from the stored data
            Book book(std::stoi(idText), title, author, issuedText == "1");

            // Displays the book details
            book.display();

            // Displays a separator
            std::cout << "-------------------------\n";
        }
    }
}

// Main function
int main() {

    // Stores the user's menu choice
    int choice;

    // Repeats the menu until the user chooses 0
    do {

        // Displays the title
        std::cout << "\nLibrary Record System\n";

        // Displays option 1
        std::cout << "1. Add Book\n";

        // Displays option 2
        std::cout << "2. Display Books\n";

        // Displays option 0
        std::cout << "0. Exit\n";

        // Asks the user to enter a choice
        std::cout << "Enter choice: ";

        // Reads the user's choice
        std::cin >> choice;

        // Performs an operation according to the choice
        switch (choice) {

            // Option 1: Add a book
            case 1:

                // Calls the addBook function
                addBook();

                // Stops this case
                break;

            // Option 2: Display books
            case 2:

                // Calls the displayBooks function
                displayBooks();

                // Stops this case
                break;

            // Option 0: Exit
            case 0:

                // Displays exit message
                std::cout << "Exiting program.\n";

                // Stops this case
                break;

            // Handles an invalid choice
            default:

                // Displays invalid choice message
                std::cout << "Invalid choice.\n";
        }

    // Continues the menu until choice becomes 0
    } while (choice != 0);

    // Returns 0 for successful execution
    return 0;
}