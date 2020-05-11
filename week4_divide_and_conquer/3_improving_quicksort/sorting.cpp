#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void partition3(vector<int> &a, int l, int r, int &m1, int &m2) {
  int x = a[l];
  m1 = l;
  m2 = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m2++;
      swap(a[i], a[m2]);
      m1++;
      swap(a[m1], a[m2]);
    } else if (a[i] == x) {
      m2++;
      swap(a[i], a[m2]);
    }
  }
  swap(a[l], a[m1]);
  swap(a[m1], a[m2]);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m1, m2;
  partition3(a, l, r, m1, m2);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int test() {
  while (true) {
    int n = rand() % 10 + 1;
    vector<int> a(n);
    vector<int> b(n);
    cout << "original" << endl;
    for (size_t i = 0; i < a.size(); ++i) {
      a[i] = rand() % 10;
      b[i] = a[i];
      cout << a[i] << " ";
    }
    cout << endl;

    randomized_quick_sort(a, 0, a.size() - 1);
    randomized_quick_sort3(b, 0, b.size() - 1);

    bool failed = false;
    for (size_t i = 0; i < a.size(); ++i)
      if (a[i] != b[i])
        failed = true;
    if (failed) {
      cout << "Error" << endl;
      break;
    }
    cout << "OK" << endl << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
