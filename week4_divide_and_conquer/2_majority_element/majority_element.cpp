#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  // write your code here
  int mid = (left + right) / 2;
  int left_majority = get_majority_element(a, left, mid);
  int right_majority = get_majority_element(a, mid, right);

  int count;
  // check left majority
  count = 0;
  for (size_t i = left; i < right; i++)
    if (a[i] == left_majority)
      count++;
  if (count > (right - left) / 2)
    return left_majority;

  // check right majority
  count = 0;
  for (size_t i = left; i < right; i++)
    if (a[i] == right_majority)
      count++;
  if (count > (right - left) / 2)
    return right_majority;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

