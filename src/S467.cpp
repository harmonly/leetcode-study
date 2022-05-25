#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        int n = p.length();
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (i && p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                ++k;
            } else
                k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};