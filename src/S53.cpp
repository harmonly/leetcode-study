#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int pre = -1e9, ans = -1e9;
        for (int i = 0; i < n; ++i) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }
};