#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), MAX = amount + 2;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - coins[j] < 0) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};

int main() {
    vector<int> coins = {3, 7, 405, 436};
    int amount = 8839;
    cout << Solution().coinChange(coins, amount) << endl;
    return 0;
}