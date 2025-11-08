
#include "iter.hpp"
#include <iostream>

template<typename T>
void print(const T n) {
  std::cout << n << std::endl;
}

int main() {
  {
    const int a[5] = {0, 1, 2, 3, 4};
    iter(a, 5, print);
  }
  {
    int a[5] = {0, 1, 2, 3, 4};
    iter(a, 5, print);
  }
}
