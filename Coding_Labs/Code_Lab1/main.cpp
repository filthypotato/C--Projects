/*
Date: 03/12/26
Program: Base class and derived class deconstructors
*/

#include <iostream>
#include <string>

// base class
class Shape {   // shape class to store protected name
protected:
  std::string name{};

public:          // public Shape to inherit name
  Shape(std::string n); // constructor for Shape class
  virtual ~Shape();  // virtual destructor for Shape

};

// Derived class
class Rectangle : public Shape { // Rectangle inherits from Shape class
private:
  double length{};

public:
  Rectangle(std::string n, double l);  // constructor for rectangle
  ~Rectangle(); // deconstructor for rectangle

  void display() const; // displays rectangle lengths
};




int main() {
  std::string recName{}; // variables to stor user input
  double recLength{};

  std::cout << "Enter rectangle name: "; // ask user to enter shape name
  std::cin >> recName;

  std::cout << "Enter rectangle length: "; // ask user to enter rectangle length
  std::cin >> recLength;

  Rectangle rec(recName, recLength); // creates the rectangle object

  std::cout << "\nRectangle Details: " << std::endl; // displays rectangle details
  rec.display();

  // to be displayed before the program ends
  std::cout << "This program is ending, calling deconstructor for shape object." << std::endl;

  return 0;
}

// Functions called after main. I assumed this is what you meant in your announment.

// Constructor for shape class

Shape::Shape(std::string n) {
  name = n;
}

// deconstructor for shape class
Shape::~Shape() {
  std::cout << "The shape object called to be destroyed!" << std::endl;
}

// Constructor for the rectangle class
Rectangle::Rectangle(std::string n, double l) : Shape(n) {
  length = l;
}

// Deconstructor for rectangle
Rectangle::~Rectangle() {
  std::cout << "Rectangle being called to be destoryed." << std::flush;
}

// Function for dsiplay
//
// Prints rectangle name and length
void Rectangle::display() const {
  std::cout << "Shape name: " << name << std::endl;
  std::cout << "Rectangle length: " << length << std::endl;
}

