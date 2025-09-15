#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int m = str1.length();
  int n = str2.length();

  int dp[m + 1][n + 1]; dp[0][0] = 0;
  for (int i = 1; i <= m; i++) dp[i][0] = i;
  for (int j = 1; j <= n; j++) dp[0][j] = j;

  int iscore, dscore, mscore;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      iscore = dp[i][j - 1] + 1;
      dscore = dp[i - 1][j] + 1;
      mscore = dp[i - 1][j - 1];

      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = min(min(iscore, dscore), mscore);
      } else {
        dp[i][j] = min(min(iscore, dscore), mscore + 1);
      }
    }
  }

  return dp[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
