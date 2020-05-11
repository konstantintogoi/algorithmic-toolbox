#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current * current;
  }

  return sum % 10;
}

long long get_fibonacci_last_digit_fast(long long n, long long m) {
  // остаток n-го числа Фибоначи по модулю m
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
    // полчаем последние цифры за два периода и сравниваем
    long long ld1 = get_fibonacci_last_digit_fast(i, m);
    long long ld2 = get_fibonacci_last_digit_fast(i + p, m);
    if (ld1 != ld2)
      return false;
  }
  return true;
}

int get_first_zero_ix(long long n, long long m) {
  // определяем индекс первого нуля среди остатков по модулю m
  long long i = 0;
  while (true) {
    i += 1;
    long long ld = get_fibonacci_last_digit_fast(i, m);
    // первое число, которое в остатке даёт 0
    if (ld == 0)
      return i;
  }
}

int get_fibonacci_period(int first_zero_ix, long long m) {
  // количество возможных нулей в периоде
  int sigmas[3]{1, 2, 4};
  int period;

  for (int i = 0; i < 3; i++)
    // подбираем период по формуле - индекс 1-го нуля x кол-во нулей
    if (is_fibonacci_period(m, first_zero_ix * sigmas[i]))
      period = first_zero_ix * sigmas[i];

  return period;
}

int fibonacci_sum_squares_fast(long long n) {
  if (n <= 1)
    return n;

  int first_zero_ix = get_first_zero_ix(n, 10);
  long long period = (long long)get_fibonacci_period(first_zero_ix, 10);

  long long p1 = n % period;
  p1 = get_fibonacci_last_digit_fast(p1, 10);
  long long p2 = (n + 1) % period;
  p2 = get_fibonacci_last_digit_fast(p2, 10);

  return (p1 * p2) % 10;
}

int main() {
  long long n = 0;
  std::cin >> n;
  std::cout << fibonacci_sum_squares_fast(n) << std::endl;
}
