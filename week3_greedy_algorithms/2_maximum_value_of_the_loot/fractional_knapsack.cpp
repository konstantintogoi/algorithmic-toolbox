#include <algorithm>
#include <iostream>
#include <vector>

using std::min;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  for (int i = 0; i < values.size(); i++) {
    if (capacity == 0)
      return value;

    int amax = 0;
    double maxfrac = 0.0;

    for (int j = 0; j < weights.size(); j++) {
      if (weights[j] > 0) {
        double frac = (double)values[j] / (double)weights[j];
        if (frac > maxfrac) {
          amax = j;
          maxfrac = frac;
        }
      }
    }

    int a = min(weights[amax], capacity);
    value += (double)a * (double)values[amax] / (double)weights[amax];
    weights[amax] -= a;
    capacity -= a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
