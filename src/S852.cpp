#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int low = 1, high = n - 2, ans = 0;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};