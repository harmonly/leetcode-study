#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2], ans = 0;
        for (auto& x : nums) ans += abs(mid - x);
        return ans;
    }
};