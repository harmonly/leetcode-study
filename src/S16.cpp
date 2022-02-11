#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1 << 30, n = nums.size(), diff = 1 << 30;
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                if (sum > target) --k;
                if (sum < target) ++j;
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};