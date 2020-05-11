#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

bool is_fibonacci_period(long long m, int p) {
  for (int i = 0; i < p; i++) {
    long long ld1 = get_fibonacci_last_digit_fast(i, m);
    long long ld2 = get_fibonacci_last_digit_fast(i + p, m);
    if (ld1 != ld2)
      return false;
  }
  return true;
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

int get_fibonacci_period(int first_zero_ix, long long m) {
  int sigmas[3]{1, 2, 4};
  int period;

  for (int i = 0; i < 3; i++)
    if (is_fibonacci_period(m, first_zero_ix * sigmas[i]))
      period = first_zero_ix * sigmas[i];

  return period;
}

int fibonacci_sum_fast(long long n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  int first_zero_ix = get_first_zero_ix(n, 10);
  int period = get_fibonacci_period(first_zero_ix, 10);
  n += 2;
  n %= (long long)period;
  return (get_fibonacci_last_digit_fast(n, 10) + 9) % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
  long long sum_from = fibonacci_sum_fast(from - 1);
  long long sum_to = fibonacci_sum_fast(to);
  return (10 + sum_to - sum_from) % 10;
}

int main() {
  long long from, to;
  std::cin >> from >> to;
  std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
