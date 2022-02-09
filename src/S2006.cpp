#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j)
                if (abs(nums[i] - nums[j]) == k) ++ans;
        }
        return ans;
    }

    int countKDifference2(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            ans += mp[nums[i] - k] + mp[nums[i] + k];
            mp[num]++;
        }
        return ans;
    }
};