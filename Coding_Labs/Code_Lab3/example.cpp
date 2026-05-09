#include <iostream>

class Money {
private:
    double* balance;   // pointer, so this class is managing dynamic memory
    int cents{};

public:
    Money(double amount) {
        balance = new double(amount);
    }

    Money& operator=(const Money& other) {
        if (this == &other) return *this;   // handles self-assignment

        delete balance;
        balance = new double(*other.balance);   // deep copy
        return *this;
    }

    Money operator+(const Money& other) const {
        Money result(*balance + *other.balance);   // Money + balanceA
        result.cents = cents + other.cents;
        return result;
    }

    void display() const {
      std::cout << "Balance: $" << *balance << std::endl;
    }
};

int main() {
  Money dollars(100);
  Money cents(500);
  Money total = dollars + cents;

  total.display();
}



