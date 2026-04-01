#include <iostream>
#include "vector.hpp"

bool testEmptyVector()
{
  zharov::Vector< int > v;
  return v.isEmpty();
}

bool testGetSize()
{
  zharov::Vector< int > v;
  return v.getSize() == 0;
}

bool testGetCapacity()
{
  zharov::Vector< int > v;
  return v.getCapacity() == 0;
}

bool testPushBack()
{
  zharov::Vector< int > v;
  v.pushBack(1);
  return v[0] == 1 && v.getSize() == 1 && v.getCapacity() == 2;
}

bool testPopBack()
{
  zharov::Vector< int > v;
  v.pushBack(1);
  v.popBack();
  return v.getSize() == 0 && v.getCapacity() == 2;
}

bool testElementInBoundAccess()
{
  zharov::Vector< int > v;
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
  zharov::Vector< int > v;
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
  zharov::Vector< int > v;
  v.pushBack(1);
  const zharov::Vector< int > & cv = v;
  try {
    const int & val = cv.at(0);
    return val == 1;
  } catch (...) {
    return false;
  }
}

bool testElementOutOfBoundConstAccess()
{
  const zharov::Vector< int > v;
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
  zharov::Vector< int > v;
  zharov::Vector< int > cv = v;
  return v == cv;
}

bool testCopyNoneEmptyVector()
{
  zharov::Vector< int > v;
  v.pushBack(1);
  zharov::Vector< int > cv = v;
  return v == cv;
}

bool testMoveConstractor()
{
  zharov::Vector< int > v(2, 1);
  zharov::Vector< int > cv = std::move(v);
  return cv.getSize() == 2;
}

bool testCopyOperator()
{
  zharov::Vector< int > v(2, 1);
  zharov::Vector< int > v2(3, 2);
  v = v2;
  return v.getSize() == 3 && v.at(0) == 2;
}

bool testMoveOperator()
{
  zharov::Vector< int > v(2, 1);
  zharov::Vector< int > v2(3, 2);
  v = std::move(v2);
  return v.getSize() == 3 && v.at(0) == 2;
}

bool testInsertValue()
{
  zharov::Vector< int > v(2, 1);
  v.insert(1, 0);
  return v.getSize() == 3 && v.at(1) == 0 && v.at(2) == 1;
}

bool testInsertVector()
{
  zharov::Vector< int > v(2, 1);
  zharov::Vector< int > vi(3, 0);
  v.insert(1, vi, 0, 2);
  zharov::Vector< int > vr;
  vr.pushBack(1);
  vr.pushBack(0);
  vr.pushBack(0);
  vr.pushBack(1);
  return v == vr;
}

bool testInsertSelfVector()
{
  zharov::Vector< int > v(2, 1);
  v.insert(1, v, 0, 2);
  zharov::Vector< int > vr;
  for (size_t i = 0; i < 4; ++i) {
    vr.pushBack(1);
  }
  return v == vr;
}

bool testIterInsertValue()
{
  zharov::Vector< int > v(2, 1);
  auto it = v.begin();
  v.insert(it + 1, 0);
  return v.getSize() == 3 && v.at(1) == 0 && v.at(2) == 1;
}

bool testIterInsertVector()
{
  zharov::Vector< int > v(2, 1);
  zharov::Vector< int > vi(3, 0);
  auto it = v.begin();
  auto it2 = vi.cbegin();
  v.insert(it + 1, it2, it2 + 2);
  zharov::Vector< int > vr;
  vr.pushBack(1);
  vr.pushBack(0);
  vr.pushBack(0);
  vr.pushBack(1);
  return v == vr;
}

bool testIterInsertSelfVector()
{
  zharov::Vector< int > v(2, 1);
  auto it = v.begin();
  v.insert(it + 1, v.cbegin(), v.cbegin() + 2);
  zharov::Vector< int > vr;
  for (size_t i = 0; i < 4; ++i) {
    vr.pushBack(1);
  }
  return v == vr;
}

bool testEraseValue()
{
  zharov::Vector< int > v(3, 0); 
  v.erase(1);
  return v.getSize() == 2 && v.at(1) == 0;
}

bool testEraseRange()
{
  zharov::Vector< int > v(3, 0);
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);  
  v.erase(1, 4);
  zharov::Vector< int > vr;
  vr.pushBack(0);
  vr.pushBack(2);
  vr.pushBack(3);
  return v.getSize() == 3 && v == vr;
}

bool testInitializerList()
{
  zharov::Vector< int > v{1, 2, 3};
  return v.getSize() == 3 && (v[0] == 1) && (v[1] == 2) && (v[2] == 3);
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
    {"Insert Value", testInsertValue},
    {"Insert Vector", testInsertVector},
    {"Erase Value", testEraseValue},
    {"Erase Range", testEraseRange},
    {"Insert Self Vector", testInsertSelfVector},
    {"Non-empty vector for non-empty initializer list", testInitializerList},
    {"Iter Insert Value", testIterInsertValue},
    {"Iter Insert Vector", testIterInsertVector},
    {"Iter Insert Self Vector", testIterInsertSelfVector}
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
