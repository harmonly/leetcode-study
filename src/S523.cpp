#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkSubarrySum(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (len < 2)
            return false;
        int sums[len + 1];
        sums[0] = 0;
        for (int i = 0; i < len; i++)
            sums[i + 1] = sums[i] + nums[i];

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 2; j <= len; j++)
            {
                int sum = sums[j] - sums[i];
                if (sum == 0 || sum % k == 0)
                    return true;
            }
        }
        return false;
    }

    bool checkSubarrySum2(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (len < 2)
            return false;

        unordered_map<int, int> map = {{0, -1}};
        int rem = 0;
        for (int i = 0; i < len; i++)
        {
            rem = (rem + nums[i]) % k;
            if (map.count(rem))
            {
                if (i - map[rem] > 1)
                    return true;
            }
            else
                map[rem] = i;
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {23, 2, 4, 6, 6};
    int k = 7;
    cout << Solution().checkSubarrySum2(nums, k) << endl;

    return 0;
}