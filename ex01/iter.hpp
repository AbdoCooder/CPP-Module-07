
#include <cstddef>

template<typename T>
void iter(T *array, const std::size_t len, void (*f)(T array)) {
  for (std::size_t i = 0; i < len; i++) {
    f(array[i]);
  }
}
