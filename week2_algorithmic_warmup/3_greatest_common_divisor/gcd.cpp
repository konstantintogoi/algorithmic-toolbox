#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  while (a != 0 and b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

void test() {
  while (true) {
    int a = rand() % 1000000000 + 1;
    int b = rand() % 1000000000 + 1;
    std::cout << a << ' ' << b << std::endl;
    int res1 = gcd_naive(a, b);
    int res2 = gcd_fast(a, b);
    if (res1 != res2) {
      std::cout << "Wrong answer: " << res1 << ' ' << res2 << std::endl;
      break;
    } else {
      std::cout << "OK" << std::endl;
    }
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
