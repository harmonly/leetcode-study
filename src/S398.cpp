#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    unordered_map<int, vector<int>> mp;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int n = mp[target].size();
        return mp[target][rand() % n];
    }
};

class Solution2 {
public:
    vector<int>& nums;

    Solution2(vector<int>& nums) : nums(nums) {}
    
    int pick(int target) {
        int ans, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */