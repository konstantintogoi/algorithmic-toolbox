#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) {
    b[left] = a[left];
    return number_of_inversions;
  }
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  int i = left, j = ave, pos = left;

  while (i < ave && j < right) {
    if (a[i] <= a[j]) {
      b[pos] = a[i];
      i++;
    } else {
      b[pos] = b[j];
      j++;
      number_of_inversions += ave - i;
    }
    pos++;
  }

  while (i < ave) {
    b[pos] = a[i];
    pos++; i++;
  }

  while (j < right) {
    b[pos] = a[j];
    pos++; j++;
  }

  for (size_t i = left; i < right; i++) {
    a[i] = b[i];
  }

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
