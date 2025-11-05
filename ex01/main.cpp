
#include "iter.hpp"

template<typename T>
void (*f)(T array) {
  
}

int main() {
  int a[5] = {0, 1, 2, 3, 4};
  iter(a, 5, f);
}
