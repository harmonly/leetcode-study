#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, n = nums.size();
        for (int i = 0; i < n; ++i) {  // 使用 i, j (0 <= i < j < n) 进行遍历
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) ans = max(ans, nums[j] - nums[i]);
            }
        }
        return ans;
    }

    int maximumDifference2(vector<int>& nums) {
        int ans = -1, n = nums.size();
        int pre = nums[0];             // 前缀最小值 nums[i]
        for (int i = 1; i < n; ++i) {  // 此处的 i 代表为 j 遍历后方的最大值
            if (nums[i] > pre)
                ans = max(ans, nums[i] - pre);
            else  // 如果当前值小于前缀最小值, 则更新 pre
                pre = nums[i];
        }
        return ans;
    }
};