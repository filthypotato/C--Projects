/*
Date: 04/18/26
Program: Asks user for integer, counts down from given integer to 0 using direct and indirect recursion

Revisions:
*/


#include <iostream>

// -- FWD DECLARATIONS --
void countDown(int n);
void bar(int n);
void foo(int n);


// MAIN

int main() {
  std::cout << "Enter an integer value: ";
  int num{};
  std::cin >> num;

  std::cout << "\nDirect Recursion\n";
  countDown(num); // countDown function with num as parameter

  std::cout << "\nIndirect Recursion\n";
  foo(num); // foo function with num as parameter

  return 0;
};

// Functions
void countDown(int n) {
  std::cout << n << std::endl;

  if (n > 0) {
    countDown(n - 1);
  } else {
      std::cout << "Done!" << std::endl;
  }
}

void foo(int n) {
  std::cout << n << std::endl;

  if (n > 0) {
    bar(n - 1); // calls for bar
  }
}

void bar(int n) {
  std::cout << n << std::endl;

  if (n > 0) {
    foo(n - 1); // call for foo
  }
}
