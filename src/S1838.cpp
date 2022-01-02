#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; ++r)
        {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k)
            {
                total -= nums[r] - nums[l];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 3, 4, 7, 10, 11, 11, 11, 13, 14, 16, 16, 16, 17, 20, 22, 23, 23, 23, 24, 25, 25, 25, 26, 27, 27, 28, 28, 30, 30, 30, 30, 32, 32, 33, 34, 35, 35, 36, 37, 38, 38, 43, 45, 45, 46, 47, 52, 52, 54, 54, 57, 59, 63, 64, 64, 66, 70, 72, 72, 73};
    int k = 3056;
    cout << Solution().maxFrequency(nums, k) << endl;
    return 0;
}