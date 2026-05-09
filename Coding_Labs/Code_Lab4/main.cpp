/*
Date: 04/09/26
Program: Asks user for dividend and quotient to divide. Applied a couple checks for dividing by 0 or negative dividend

Revisions:
*/

#include <iostream>
#include <string>

// fwd declaration for divideNumbers
int divideNumbers(int dividend, int divisor);

int main() {
  std::cout << "Start of main..." << std::endl;

  int dividend{}, divisor{}, quotient{}; // variables to store user input


  std::cout << "Enter dividend: "; // prompt user for dividend
  std::cin >> dividend;

  std::cout << "Enter divisor: "; // prompt user for divisor
  std::cin >> divisor;

  try {
    // calls function to store quotient
    quotient = divideNumbers(dividend, divisor);
    std::cout << "Result: " << quotient << std::endl;
  }

  //catches the division by zero exception
  catch (int c) {
      std::cout << "Error: cannot divide by 0!" << std::endl;
  }

  // catch negative dividned exeption
  catch (const std::string& message) { // ctach string exception by reference
    std::cout << "Error: " << message << std::endl;
  }

  return 0;
}

// function of divideNumbers with parameters dividend and divisor
int divideNumbers(int dividend, int divisor) { // thought about using double instead but assignment says int
  if (dividend < 0) {
    throw std::string("Cannot have a negative dividend"); // throws this error if divisor is < 0
  }

  if (divisor == 0) { // checks if divisor is 0 and throws excepetion
    throw -1;
  }

  return dividend / divisor; // division of dividend and divisor
}
