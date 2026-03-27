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

bool testCopyConstractor()
{
  topit::Vector< int > v;
  topit::Vector< int > cv = v;
  return v == cv;
}

bool testCopyNoneEmptyVector()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > cv = v;
  return v == cv;
}

bool testMoveConstractor()
{
  topit::Vector< int > v(2, 1);
  topit::Vector< int > cv = std::move(v);
  return cv.getSize() == 2;
}

bool testCopyOperator()
{
  topit::Vector< int > v(2, 1);
  topit::Vector< int > v2(3, 2);
  v = v2;
  return v.getSize() == 3 && v.at(0) == 2;
}

bool testMoveOperator()
{
  topit::Vector< int > v(2, 1);
  topit::Vector< int > v2(3, 2);
  v = std::move(v2);
  return v.getSize() == 3 && v.at(0) == 2;
}

bool testInsertValue()
{
  topit::Vector< int > v(2, 1);
  v.insert(1, 0);
  return v.getSize() == 3 && v.at(1) == 0 && v.at(2) == 1;
}

bool testInsertVector()
{
  topit::Vector< int > v(2, 1);
  topit::Vector< int > vi(3, 0);
  v.insert(1, vi, 0, 2);
  topit::Vector< int > vr;
  vr.pushBack(1);
  vr.pushBack(0);
  vr.pushBack(0);
  vr.pushBack(1);
  return v == vr;
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
    {"Element out of bound const access", testElementOutOfBoundConstAccess},
    {"Copy Empty Vector", testCopyConstractor},
    {"Copy None Empty Vector", testCopyNoneEmptyVector},
    {"Move Constractor", testMoveConstractor},
    {"Copy Operator", testCopyOperator},
    {"Move Operator", testMoveOperator},
    {"testInsertValue", testInsertValue},
    {"testInsertVector", testInsertVector}
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
