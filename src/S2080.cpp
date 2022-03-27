#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int m = rolls.size();
        int sum = (n + m) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (sum / n > 6 || sum < n) return ans;
        for (int i = 0; i < n; ++i) ans.push_back(sum / n);
        int left = sum % n;
        int j = 0;
        while (left) {
            ans[j++]++;
            if (j == n || ans[j - 1] > 6) return vector<int>();
            --left;
        }
        return ans;
    }
};