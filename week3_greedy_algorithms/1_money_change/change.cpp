#include <iostream>

int get_change(int m) {
  //write your code here
  int  denominations[] {10, 5, 1};
  int num_coins = 0;
  for (int i = 0; i < 3; i++) {
      num_coins += m / denominations[i];
      m %= denominations[i];
  }
  return num_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
