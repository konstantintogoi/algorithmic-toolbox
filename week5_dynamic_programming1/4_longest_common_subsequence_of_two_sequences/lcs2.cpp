#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int m = a.size();
  int n = b.size();

  int dp[m + 1][n + 1]; dp[0][0] = 0;
  for (int i = 0; i <= m; i++) dp[i][0] = 0;
  for (int j = 0; j <= n; j++) dp[0][j] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) cin >> a[i];

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) cin >> b[i];

  cout << lcs2(a, b) << endl;
}
