#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


vector<int> fast_count_segments(vector<int> starts, vector<int> ends,
                                vector<int> points) {
  vector<int> cnt(points.size());
  // write your code here

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends,
                                 vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int test() {
  while (true) {
    int n = rand() % 10 + 1;
    int m = rand() % 10 + 1;
    std::cout << n << " " << m << std::endl;
    vector<int> starts1;
    vector<int> ends1;
    vector<int> starts2;
    vector<int> ends2;
    for (int i = 0; i < n; i++) {
      int a = rand() % 10 - 5;
      int b = rand() % 10 - 5;

      if (a < b) {
        starts1.push_back(a);
        starts2.push_back(a);
        ends1.push_back(b);
        ends2.push_back(b);
        std::cout << a << " " << b << std::endl;
      } else {
        starts1.push_back(b);
        starts2.push_back(b);
        ends1.push_back(a);
        ends2.push_back(a);
        std::cout << b << " " << a << std::endl;
      }
    }
    vector<int> points1;
    vector<int> points2;
    for (int j = 0; j < m; j++) {
      int point = rand() % 10 - 5;
      points1.push_back(point);
      points2.push_back(point);
      std::cout << point << " ";
    }
    std::cout << std::endl;

    vector<int> naive = naive_count_segments(starts1, ends1, points1);
    vector<int> fast = fast_count_segments(starts2, ends2, points2);

    bool flag = false;
    for (size_t i = 0; i < naive.size(); i++) {
      if (naive[i] != fast[i]) {
        flag = true;
        break;
      }
    }

    if (flag) {
      std::cout << "Wrong answer" << std::endl;
      for (int i = 0; i < naive.size(); i++) {
        std::cout << naive[i] << " ";
      }
      std::cout << std::endl;
      for (int i = 0; i < naive.size(); i++) {
        std::cout << fast[i] << " ";
      }
      std::cout << std::endl;
      break;
    } else {
      std::cout << "OK" << std::endl;
    }
  }
  return 0;
}

int solve() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  // use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}

int main() {
  return solve();
}
