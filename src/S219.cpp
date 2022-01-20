#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (mp.count(num) && i - mp[num] <= k) return true;
            mp[num] = i;
        }
        return false;
    }

    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (i > k) s.erase(nums[i - k - 1]);
            if (s.count(num)) return true;
            s.emplace(num);
        }
        return false;
    }
};