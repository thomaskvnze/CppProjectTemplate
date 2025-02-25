#include "my_lib.h"

#include <iostream>
#include <nlohmann/json.hpp>

int print_hello_world() {
  std::cout << "Cout: Hello World" << '\n';
  std::cout << NLOHMANN_JSON_VERSION_MAJOR << '\n';

  // Adress Sanitizer should see this
  int* x = new int[42];

  return 1;
}

unsigned int factorial(unsigned int number) {
  return number <= 1 ? 1 : factorial(number - 1) * number;
}
