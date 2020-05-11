#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops) {
  int num_refills = 0;
  int pos = 0;
  int jump = 1;

  while (tank >= stops[pos + jump] - stops[pos]) {
    if (stops[pos + jump] == dist)
      return num_refills;
    if (stops[pos + jump + 1] - stops[pos] > tank) {
      pos = pos + jump;
      num_refills += 1;
      jump = 1;
    } else {
      jump++;
    }
  }

  return -1;
}

int main() {
  int d = 0;
  cin >> d;
  int m = 0;
  cin >> m;
  int n = 0;
  cin >> n;

  vector<int> stops(n);
  for (size_t i = 0; i < n; ++i)
    cin >> stops.at(i);

  auto it = stops.insert(stops.begin(), 0);
  stops.insert(stops.end(), d);

  cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}
