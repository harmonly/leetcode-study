#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarrysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int sums[n + 1];
        sums[0] = 0;
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];

        int res = 0;
        unordered_map<int, int> map;
        for (auto &sum : sums)
        {
            int tmp = sum - goal;
            if (tmp > 0)
                res += map[tmp];
            map[sum]++;
        }

        return res;
    }

    int numSubarrysWithSum2(vector<int> &nums, int goal)
    {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (auto &num : nums)
        {
            cnt[sum]++;
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << Solution().numSubarrysWithSum(nums, goal) << endl;
    return 0;
}