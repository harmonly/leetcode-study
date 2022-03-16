#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), prev = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (prev != -1 && i - prev - 1 < k) return false;
                prev = i;
            }
        }
        return true;
    }
};