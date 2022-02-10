#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, n = nums.size();
        for (int i = 0; i <= n - k; ++i)
            ans = min(ans, nums[i + k - 1] - nums[i]);
        return ans;
    }
};