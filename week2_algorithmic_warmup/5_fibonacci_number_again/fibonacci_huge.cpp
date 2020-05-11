#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

long long get_fibonacci_last_digit_fast(long long n, long long m) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current = 1;

  for (int i = 0; i < n - 1; ++i) {
    long long tmp = previous;
    previous = current;
    current = (tmp + current) % m;
  }

  return current % m;
}

int get_first_zero_ix(long long n, long long m) {
  long long i = 0;
  while (true) {
    i += 1;
    long long ld = get_fibonacci_last_digit_fast(i, m);
    if (ld == 0)
      return i;
  }
}

bool is_fibonacci_period(long long m, int p) {
  for (int i = 0; i < p; i++) {
    long long ld1 = get_fibonacci_last_digit_fast(i, m);
    long long ld2 = get_fibonacci_last_digit_fast(i + p, m);
    if (ld1 != ld2)
      return false;
  }
  return true;
}

int get_fibonacci_period(long long n, long long m) {
  int sigmas[3]{1, 2, 4};
  int period;

  int first_zero_ix = get_first_zero_ix(n, m);

  for (int i = 0; i < 3; i++) {
    if (is_fibonacci_period(m, first_zero_ix * sigmas[i]))
      period = first_zero_ix * sigmas[i];
  }

  return period;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
  if (n <= 1)
    return n;

  int period = get_fibonacci_period(n, m);
  n %= (long long)period;

  return get_fibonacci_last_digit_fast(n, m);
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

