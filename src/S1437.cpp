#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), pre = -1;
        for (int i = 0; i < n; ++i)
            if (nums[i]) {
                pre = i;
                break;
            }
        for (int i = pre + 1; i < n; ++i) {
            if (!nums[i]) continue;
            if (i - pre - 1 >= k)
                pre = i;
            else
                return false;
        }
        return true;
    }
};