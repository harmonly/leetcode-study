#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return nums;
    }

    vector<int> runningSum2(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) nums[i] += nums[i - 1];
        return nums;
    }
};