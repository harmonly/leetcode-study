#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; ++i)
        {
            int low = i + 1, high = n - 1;
            while (low <= high)
            {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i])
                    return {i + 1, mid + 1};
                else if (numbers[mid] > target - numbers[i])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum2(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};
            else if (sum > target)
                right--;
            else
                left++;
        }
        return {-1, -1};
    }
};