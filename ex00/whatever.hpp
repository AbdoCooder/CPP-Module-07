#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(const T &param1, const T &param2) {
  T tmp = param1;
  param1 = param2;
  param2 = tmp;
}

template <typename T>
T &min(const T &param1, const T &param2) {
  return (param1 < param2 ? param1 : param2);
}

template <typename T>
T &max(T &param1, T &param2) {
  return (param1 > param2 ? param1 : param2);
}

#endif
