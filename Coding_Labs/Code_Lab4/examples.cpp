#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>

// 1: Exception class
class VolatilityLimitException {
private:
  std::string message{};

public:
  VolatilityLimitException() {
    message = "Volatility limit reached!";
  }

  VolatilityLimitException(std::string str) {
    message = str + " limit reached!";
  }

  std::string what() {
    return message;
  }
};


// 2. Friend function
class B;

class A {
private:
  int secretKeys{};

public:
  friend void showKeys(const A&, const B&); // friend delcation
};

class B {
private:
  int hiddenData{};

public:
  friend void showKeys(const A&, const B&);
};

void showKeys(const A& a, const B& b) {
  std::cout << a.secretKeys << " and " << b.hiddenData << std::endl;
}

// 3. when friend is necessary
class Station; //fwd declaration

class Train {
private:
  int passengers{100};

public:
  friend void show(const Train&, const Station&);
};

class Station {
private:
  int platforms{5};

public:
  friend void show(const Train&, const Station&);
};

void show(const Train& t, const Station& s) {
  std::cout << t.passengers << " " << s.platforms << std::endl;
}

int main() {
  Train t;
  Station s;
  show(t, s);
}


