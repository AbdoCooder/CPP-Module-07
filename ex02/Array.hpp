// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>    // for NULL
#include <stdexcept>  // for out_of_range

template<typename T> class Array {
  public:
    Array() : array(NULL), _size(0) {};

    Array(unsigned int n) {
      this->array = new T[n](); // () so elements will be initialized to 0
      this->_size = n;
    }

    Array(const Array &other) {
      this->array = new T[other._size];
      for (unsigned int i = 0; i < other._size; i++) {
        this->array[i] = other.array[i];
      }
      this->_size = other._size;
    }

    Array &operator=(const Array &other) {
      if (this != &other) {
        delete [] this->array;
        this->_size = other._size;
        this->array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++) {
          this->array[i] = other.array[i];
        }
      }
      return *this;
    }

    ~Array() {
      delete [] this->array;
      this->array = NULL;
      this->_size = 0;
    }

    // for reading like std::cout << array[i]
    const T &operator[](const unsigned int &n) const {
      if (n >= _size) {
        throw std::out_of_range("The index is out of bound!");
      } else {
        return this->array[n];
      }
    }

    // for writing like array[i] = 10;
    T &operator[](const unsigned int &n) {
      if (n >= _size) {
        throw std::out_of_range("The index is out of bound!");
      } else {
        return this->array[n];
      }
    }

    unsigned int size(void) const {
      return _size;
    }

  private:
    T *array;
    unsigned int _size;
};

#endif //  ARRAY_HPP
