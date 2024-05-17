#include <pybind11/pybind11.h>
#include <iostream>

int greetings(void) {
  std::cout << "Hello from Python" << std::endl;
  return 42;
}

PYBIND11_MODULE(_test_ext, m) {
  m.def("greetings" , &greetings);
}
