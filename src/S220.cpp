#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> ms;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > k) ms.erase(nums[i - k - 1]);
            auto it = ms.lower_bound(max(nums[i], INT_MIN + t) -
                                     t);  // 最小不能小于 INT_MIN
            if (it != ms.end() && *it <= min(nums[i], INT_MAX - t) + t)
                return true;  // 最大不能大于 INT_MAX
            ms.insert(nums[i]);
        }
        return false;
    }
};
// 使用 multiset 存储, 查找值的时间复杂度为 O(logn)
// 找到 y >= [x - t] && y <= [x + t], 满足返回 true