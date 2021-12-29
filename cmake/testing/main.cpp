#include "apple.h"
#include "vector"
#include "iostream"
#include "array"
#include "bitset"
#include "cmath"
#include "chrono"

constexpr size_t BitCount(size_t x) {
  int count = 0;
  for (; x != 0; ++count) {
    x &= x - 1;
  }
  return count;
}

constexpr int const_abs(int x) {
  return x > 0 ? x : -x;
}

constexpr int square_root(int x) {
  double r = x, dx = x;
  while (const_abs((r * r) - dx) > 0.1)
    r = (r + dx / r) / 2;
  return static_cast<int>(r);
}

constexpr bool IsPrime(int x) {
  if (x == 1) {
    return false;
  }
  if (x % 2 == 0) {
    return x == 2;
  }
  int max_check = static_cast<int>(square_root(x)) + 1;
  for (int i = 3; i < max_check; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

constexpr int Factor(int x) {
  int n = 1;
  for (int i = 2; i <= x; ++i) {
    n *= i;
  }
  return n;
}

int main() {
  auto now = std::chrono::high_resolution_clock::now();
  int x = IsPrime(Factor(10) + 1);
  auto count = std::chrono::duration_cast<std::chrono::nanoseconds>(now -
      std::chrono::high_resolution_clock::now()).count();
  std::cout << x << " " << count << std::endl;

  int val = 0;
  std::cin >> val;
  now = std::chrono::high_resolution_clock::now();
  x = IsPrime(Factor(val) + 1);
  count = std::chrono::duration_cast<std::chrono::nanoseconds>(now -
      std::chrono::high_resolution_clock::now()).count();
  std::cout << x << " " << count << std::endl;
}
