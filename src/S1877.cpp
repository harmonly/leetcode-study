#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n / 2; i++)
            res = max(res, nums[i] + nums[n - i - 1]);
        return res;
    }
};