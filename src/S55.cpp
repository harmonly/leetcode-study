#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), _max = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= _max) {
                _max = max(_max, i + nums[i]);
                if (_max >= n - 1) return true;
            }
        }
        return false;
    }

    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        int next = 0;
        for (int i = 0; i < n; ++i) {
            next = max(next, i + nums[i]);
            if (next >= n - 1)
                return true;
            else if (next == i)
                return false;
        }
        return false;
    }
};