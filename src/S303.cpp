#include <bits/stdc++.h>

using namespace std;

class NumArray {
   public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.push_back(nums[0]);
        for (int i = 0; i < n; ++i) sum.push_back(sum.back() + nums[i]);
    }

    int sumRange(int left, int right) { return sum[right + 1] - sum[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */