#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(int a, int b) {
  while (a != 0 and b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return (long long)a + (long long)b;
}

long long lcm_fast(int a, int b) {
  long long gcd = gcd_fast(a, b);
  return (long long)a * (long long)b / gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

