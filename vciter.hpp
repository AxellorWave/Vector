#ifndef VCITER_HPP
#define VCITER_HPP
#include <cstddef>

namespace zharov {
  template< class T >
  struct VCIter {
    VCIter();
    explicit VCIter(T * ptr);
    const T & operator*() const;
    const T * operator->() const;
    const T & operator[](std::ptrdiff_t n) const;
    
    VCIter< T > & operator++();
    VCIter< T > operator++(int);
    VCIter< T > & operator--();
    VCIter< T > operator--(int);
    VCIter< T > operator-(std::ptrdiff_t n) const;
    VCIter< T > operator+(std::ptrdiff_t n) const;
    std::ptrdiff_t operator-(const VCIter< T > & other);

    bool operator==(const VCIter & other) const noexcept;
    bool operator!=(const VCIter & other) const noexcept;
    bool operator>(const VCIter & other) const noexcept;
    bool operator<(const VCIter & other) const noexcept;
    bool operator>=(const VCIter & other) const noexcept;
    bool operator<=(const VCIter & other) const noexcept;
  private:
    T * ptr_;
  };
}

#endif
