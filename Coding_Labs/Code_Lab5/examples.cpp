#include <iostream>



void countDown(int n) {
    if (n == 0) {  // base case
      std::cout << "Done!" << std::endl;
        return;
    }
    std::cout << n << std::endl;
    countDown(n - 1);  // recursive call
}


int main() {
  countDown(25);
};




! =, < =, > =, = =

!=, <=, >=, ==
