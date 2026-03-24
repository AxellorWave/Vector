#include <iostream>
#include "top-it-vector.hpp"

bool testEmptyVector()
{
  topit::Vector< int > v;
  return v.isEmpty();
}

bool testGetSize()
{
  topit::Vector< int > v;
  return v.getSize() == 0;
}

bool testGetCapacity()
{
  topit::Vector< int > v;
  return v.getCapacity() == 0;
}

bool testPushBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return v[0] == 1 && v.getSize() == 1 && v.getCapacity() == 2;
}

bool testPopBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.popBack();
  return v.getSize() == 0 && v.getCapacity() == 2;
}

int main()
{
  using test_t = std::pair< const char *, bool(*)() >;
  test_t tests[] = {
    {"Empty vector", testEmptyVector},
    {"Vector size", testGetSize},
    {"Capasity size", testGetCapacity},
    {"Push back", testPushBack},
    {"Pop back", testPopBack}
  };
  const size_t count = sizeof(tests) / sizeof(test_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i].second();
    std::cout << tests[i].first << ": " << res << "\n";
    pass = pass && res;
  }
  std::cout << "RESULT: " << pass << "\n";
}
// подсчет пройденных и непройденных.
// Выводить только не прошедшие тесты