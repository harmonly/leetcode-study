#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int sums[n + 2];
        memset(sums, 0, sizeof(sums));
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++)
        {
            int sum = sums[i];
            if (sums[i - 1] == sums[n] - sum)
                return i - 1;
        }
        return -1;
    }

    int pivotIndex2(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * sum + nums[i] == total)
                return i;
            sum += nums[i];
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {-1, -1, 0, 1, 1, 0};
    cout << Solution().pivotIndex(nums) << endl;
    return 0;
}