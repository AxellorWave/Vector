#ifndef VITER_HPP
#define VITER_HPP
#include <cstddef>

namespace zharov {
  template< class T >
  struct VIter {
    VIter();
    explicit Viter(T * ptr);
    T & operator*() const;
    T * operator->() const;
    T & operator[](std::ptrdiff_t n) const;
    
    VIter< T > & operator++();
    VIter< T > operator++(int);
    VIter< T > & operator--();
    VIter< T > operator--(int);
    VIter< T > operator-(std::ptrdiff_t n) const;
    VIter< T > operator+(std::ptrdiff_t n) const;
    std::ptrdiff_t operator-(const VIter< T > & other);

    bool operator==(const VIter & other) const noexcept;
    bool operator!=(const VIter & other) const noexcept;
    bool operator>(const VIter & other) const noexcept;
    bool operator<(const VIter & other) const noexcept;
    bool operator>=(const VIter & other) const noexcept;
    bool operator<=(const VIter & other) const noexcept;
  private:
    T * ptr_;
  };
}

#endif
