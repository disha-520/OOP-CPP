#include <iostream>                         // Includes the input-output stream library

class Animal {                              // Defines the Animal base class

public:                                     // Declares public members

    // Defines a virtual sound function
    virtual void sound() const {

        // Displays the Animal sound message
        std::cout << "Animal makes a sound\n";
    }

    // Defines a virtual destructor
    virtual ~Animal() = default;
};                                          // Ends the Animal class


class Dog : public Animal {                 // Defines Dog class inheriting from Animal

public:                                     // Declares public members

    // Overrides the sound function of Animal
    void sound() const override {

        // Displays the sound made by a dog
        std::cout << "Dog barks\n";
    }
};                                          // Ends the Dog class


class Cat : public Animal {                 // Defines Cat class inheriting from Animal

public:                                     // Declares public members

    // Overrides the sound function of Animal
    void sound() const override {

        // Displays the sound made by a cat
        std::cout << "Cat meows\n";
    }
};                                          // Ends the Cat class


int main() {                                // Main function where execution starts

    Dog dog;                                // Creates an object of Dog class

    Cat cat;                                // Creates an object of Cat class

    // Creates an Animal pointer pointing to the Dog object
    Animal* animal = &dog;

    // Calls Dog's sound() through the Animal pointer
    animal->sound();

    // Changes the pointer to point to the Cat object
    animal = &cat;

    // Calls Cat's sound() through the Animal pointer
    animal->sound();

    return 0;                               // Returns 0 for successful execution
}                                           // Ends the main() function