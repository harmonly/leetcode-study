#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canIWin(int x, int total) {
        if (x * (x + 1) / 2 < total) return false;
        vector<int> dp(1 << x);
        return dfs(x, 0, total, dp);
    }

    bool dfs(int x, int used, int target, vector<int>& dp) {
        if (dp[used]) return 1;
        for (int i = 0; i < x; ++i) {
            if (used & (1 << i)) continue;
            if (target - i - 1 <= 0 ||
                !dfs(x, used | (1 << i), target - i - 1, dp)) {
                dp[used] = 1;
                return 1;
            }
        }
        return 0;
    }
};