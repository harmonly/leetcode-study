#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.length();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        int cnt[26];
        function<int(int)> dfs = [&](int mask) {
            if (dp[mask] != -1) return dp[mask];
            dp[mask] = m + 1;
            for (auto& sticker : stickers) {
                memset(cnt, 0, sizeof(cnt));
                for (auto& c : sticker) cnt[c - 'a']++;
                int left = mask;
                for (int i = 0; i < m; ++i) {
                    if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                        cnt[target[i] - 'a']--;
                        left ^= 1 << i;
                    }
                }
                if (left < mask) dp[mask] = min(dp[mask], dfs(left) + 1);
            }
            return dp[mask];
        };
        int ans = dfs((1 << m) - 1);
        return ans > m ? -1 : ans;
    }
};