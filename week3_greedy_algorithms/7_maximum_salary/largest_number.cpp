#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool gt(string a, string b) {
  if (stoi(a + b) > stoi(b + a))
    return true;
  else
    return false;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;

  while (!a.empty()) {
    size_t amax = -1;
    string maxstring = string(1, '0');
    for (size_t i = 0; i < a.size(); i++) {
      if (gt(a[i], maxstring)) {
        amax = i;
        maxstring = a[i];
      }
    }
    ret << maxstring;
    a.erase(a.begin() + amax);
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
