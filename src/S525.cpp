#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int len = nums.size();
        int rem = 0;
        unordered_map<int, int> map = {{0, -1}};
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            rem += nums[i] == 0 ? -1 : 1;
            if (map.count(rem))
                res = max(res, i - map[rem]);
            else
                map[rem] = i;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1};
    cout << Solution().findMaxLength(nums) << endl;
    return 0;
}