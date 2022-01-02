#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;)
        {
            int first = nums[i] * nums[i], last = nums[j] * nums[j];
            if (first > last)
            {
                ans[pos] = first;
                i++;
            }
            else
            {
                ans[pos] = last;
                j--;
            }
            pos--;
        }
        return ans;
    }
};