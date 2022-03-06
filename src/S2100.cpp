#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> ans, left(n), right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) left[i] = left[i - 1] + 1;
            if (security[n - i - 1] <= security[n - i])
                right[n - i - 1] = right[n - i] + 1;
        }
        for (int i = time; i < n - time; ++i)
            if (left[i] >= time && right[i] >= time) ans.push_back(i);
        return ans;
    }
};