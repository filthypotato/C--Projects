/*
Date: 03/26/26
Program: Asks user for width and length of rectangles, displays larger area of Rect1/Rect2
Revisions:
*/


#include <iostream>

class Rectangle { // class regtangle
private: // privat variables
  double length{}; // stores length of rectangle
  double width{}; // stores width of rectangle

public:
  Rectangle(double l, double w); // constructor for Rectangle

  // declaration function for friend
  friend double calculateArea(const Rectangle& r);
  // declatation for compareing rectangles
  friend void compareRectangle(const Rectangle& r1, const Rectangle& r2);

  void display() const;
};


int main() {
  double l1, w1, w2, l2{};


  // User input for length
  std::cout << "Enter length and width for Rect1 (separate by space): ";
  std::cin >> l1 >> w1;

  Rectangle rect1(l1, w1); // creates 1st object

  // user input for width
  std::cout << "Enter length and width for Rect2 (separate by space): ";
  std::cin >> l2 >> w2;

  Rectangle rect2(l2, w2); // creates 2nd object

  // Displays output
  std::cout << "\nRect 1 details: " << std::endl;
  rect1.display();

  std::cout << "Area: " << calculateArea(rect1) << std::endl;

  std::cout << "\nRect 2 details: " << std::endl;
  rect2.display();

  std::cout << "Area: " << calculateArea(rect2) << std::endl;

  // rects comparison
  std::cout << "\nComparison: " << std::endl;
  compareRectangle(rect1, rect2);

  return 0;
}

// definition for friend function
double calculateArea(const Rectangle& r) {
  return r.length * r.width;
}

void compareRectangle(const Rectangle& r1, const Rectangle& r2) {
  double area1 = calculateArea(r1);
  double area2 = calculateArea(r2);

  if (area1 > area2) {
    std::cout << "Rect1 area is larger" << std::endl;
  } else if (area2 > area1) {
    std::cout << "Rect2 area is larger" << std::endl;
  } else {
    std::cout << "Both Rects have the same area" << std::endl;
  }
}

 void Rectangle::display() const {
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
  }

Rectangle::Rectangle(double l, double w) { // constructor for Rectangle
    length = l;
    width = w;
  }
