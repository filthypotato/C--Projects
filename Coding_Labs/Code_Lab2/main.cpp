/*
Date: 03/19/26
Program: Dynamcally allocating memory of an arry, takes user input, doubles it, prints results

*/

#include <iostream> // library for I/O

void doubleArrayValues(int* arrPtr, int size); // declared function for doubleArrValues

int main() {
  std::cout << "Enter size of array: "; // Asking user to input size of array

  int size{}; // variable to store the size
  std::cin >> size; // reads array size from the user


  int* arrPtr = new int[size]; // dynamiclly allocated array to heap


  for (int i = 0; i < size; i++) { // for loop to ask user to enter value for each value
    std::cout << "Enter int value: " << i << ": ";
    std::cin >> arrPtr[i];
  }

  // calling function
  doubleArrayValues(arrPtr, size);

  std::cout << "Doubled Array Values: "; // Prints doubled values of arrays
  for (int i = 0; i < size; i++) {
    std::cout << arrPtr[i] << " ";
  }

  std::cout << std::endl;

  delete[] arrPtr; // deletes arrPtr to avoid memory leaks

  arrPtr = nullptr;

  return 0;
}

// function to double the array values
void doubleArrayValues(int* arrPtr, int size) {
  for (int i = 0; i < size; i++) {
    arrPtr[i] *= 2; // doubles the array values input by user
  }
}
