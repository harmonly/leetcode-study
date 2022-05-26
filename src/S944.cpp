#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].length();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                if (strs[j][i] < strs[j - 1][i]) {
                    ++ans;
                    break;
                }
        }
        return ans;
    }
};