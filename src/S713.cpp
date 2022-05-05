#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int l = 0, prod = 1;
        for (int r = 0; r < n; ++r) {
            prod *= nums[r];
            while (l <= r && prod >= k) prod /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};