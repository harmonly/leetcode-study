#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, ans = nums[0];
        for (const auto &num : nums)
        {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};