#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] > nums[ans]) ans = i;
        for (int i = 0; i < n; ++i)
            if (i != ans && nums[ans] < nums[i] * 2) return -1;
        return ans;
    }

    int dominantIndex2(vector<int>& nums) {
        int m1 = -1, m2 = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                index = i;
            } else if (nums[i] > m2)
                m2 = nums[i];
        }
        return m1 >= 2 * m2 ? index : -1;
    }
};