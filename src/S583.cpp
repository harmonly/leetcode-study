#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        // 参考 1143题 dp定义为两个字符串的最长公共子序列
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n1 + n2 -
               2 * dp[n1][n2];  // 这里减去最长的子序列即为需要删除的长度
    }

    int minDistance2(string word1, string word2) {
        // 直接定义dp为删除的字符长度
        int n1 = word1.size(), n2 = word2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; ++i) dp[i][0] = i;
        for (int j = 0; j <= n2; ++j) dp[0][j] = j;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[n1][n2];
    }
};