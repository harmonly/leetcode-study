#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 != 0) nums[n - 1] *= -1;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};