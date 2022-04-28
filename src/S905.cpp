#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) continue;
            swap(nums[idx++], nums[i]);
        }
        return nums;
    }
};

class Solution2 {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [&](int a, int b) { return (a & 1) < (b & 1); });
        return nums;
    }
};