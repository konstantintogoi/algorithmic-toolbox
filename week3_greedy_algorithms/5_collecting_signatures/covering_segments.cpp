#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool comp(Segment a, Segment b) { return (a.start < b.start); }

vector<int> optimal_points(vector<Segment> &segments) {
  size_t n = segments.size();
  vector<int> points;

  // сортируем по первым координатам отрезков
  std::sort(segments.begin(), segments.end(), comp);

  while (!segments.empty()) {
    int amin = 0;
    long long end = LLONG_MAX;

    for (size_t i = 0; i < segments.size(); i++) {
      if (segments[i].end < end) {
        amin = i;
        end = segments[i].end;
      }
    }

    // добавляем правый конец в покрытие
    points.push_back(segments[amin].end);

    // удаляем покрытые сегменты
    for (auto it = segments.begin(); it != segments.end();)
      if (((Segment)(*it)).start <= end)
        segments.erase(it);
      else
        it++;
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
