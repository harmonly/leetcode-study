#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; i++)
            newArr[(i + k) % n] = nums[i];
        nums.assign(newArr.begin(), newArr.end());
    }

    void rotate2(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
            swap(nums[start++], nums[end--]);
    }
};