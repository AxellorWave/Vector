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

bool testElementInBoundAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  try {
    int & val = v.at(0);
    return val == 1;
  } catch (...) {
    return false;
  }
}

bool testElementOutOfBoundAccess()
{
  topit::Vector< int > v;
  try {
    v.at(0);
    return false;
  } catch (const std::out_of_range & e) {
    return true;
  } catch (...) {
    return false;
  }
}

bool testElementInBoundConstAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  const topit::Vector< int > & cv = v;
  try {
    const int & val = cv.at(0);
    return val == 1;
  } catch (...) {
    return false;
  }
}

bool testElementOutOfBoundConstAccess()
{
  const topit::Vector< int > v;
  try {
    v.at(0);
    return false;
  } catch (const std::out_of_range & e) {
    return true;
  } catch (...) {
    return false;
  }
}

int main()
{
  using test_t = std::pair< const char *, bool(*)() >;
  test_t tests[] = {
    {"Empty vector", testEmptyVector},
    {"Vector size", testGetSize},
    {"Capasity size", testGetCapacity},
    {"Push back", testPushBack},
    {"Pop back", testPopBack},
    {"Element in bound acess", testElementInBoundAccess},
    {"Element out of bound access", testElementOutOfBoundAccess},
    {"Element in bound const acess", testElementInBoundConstAccess},
    {"Element out of bound const access", testElementOutOfBoundConstAccess}
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
