#include <bits/stdc++.h>

using namespace std;

class Solution {
    int pre[20002], suf[20002];

   public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        for (int i = 1; i <= n; ++i) pre[i] = max(pre[i - 1], height[i - 1]);
        for (int i = n; i; --i) suf[i] = max(suf[i + 1], height[i - 1]);
        for (int i = 1; i <= n; ++i) ans += min(pre[i], suf[i]) - height[i - 1];
        return ans;
    }
};