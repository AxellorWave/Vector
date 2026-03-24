#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>

namespace topit {
  template <class T >
  struct Vector {
    ~Vector();
    Vector();
    Vector(const Vector &);
    Vector(Vector &&);
    Vector & operator=(const Vector &);
    Vector & operator=(Vector &&);

    T & operator[](size_t id) noexcept;
    const T & operator[](size_t id) const noexcept;
    T & at(size_t id);
    const T & at(size_t id) const;

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    void extend(size_t new_capacity);
    void pushBack(const T & v);
    void popBack();
    void insert(size_t i, const T & v);
    void erase(size_t i);

  private:
    T * data_;
    size_t size_, capacity_;
  };
}

template< class T >
topit::Vector< T >::~Vector()
{
  delete[] data_;
}

template< class T >
topit::Vector< T >::Vector():
  data_(nullptr),
  size_(0),
  capacity_(0)
{}

template< class T >
const T & topit::Vector< T >::operator[](size_t id) const noexcept
{
  return data_[id];
}

template< class T >
T & topit::Vector< T >::operator[](size_t id) noexcept
{
  return data_[id];
}

template< class T >
const T & topit::Vector< T >::at(size_t id) const
{
  if (id < getSize()) {
    return data_[id];
  }
  throw std::range_error("Bad index");
}

template< class T >
T & topit::Vector< T >::at(size_t id)
{
  if (id < getSize()) {
    return data_[id];
  }
  throw std::range_error("Bad index");
}

template< class T >
bool topit::Vector<T>::isEmpty() const noexcept
{
  return !size_;
}

template< class T >
size_t topit::Vector< T >::getSize() const noexcept
{
  return size_;
}

template< class T >
size_t topit::Vector< T >::getCapacity() const noexcept
{
  return capacity_;
}

template< class T >
void topit::Vector< T >::extend(size_t new_capacity)
{
  T * new_data = new T[new_capacity];
  for (size_t i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template< class T >
void topit::Vector< T >::pushBack(const T & v)
{
  if (isEmpty()) {
    extend(2);
  }
  if (size_ == capacity_) {
    extend(capacity_ * 2);
  }
  data_[size_] = v;
  ++size_;
}
template< class T >
void topit::Vector< T >::popBack()
{
  --size_;
}

#endif
