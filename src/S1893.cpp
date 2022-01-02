#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        sort(ranges.begin(), ranges.end(), [&](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        for (auto &range : ranges)
        {
            int start = range[0], end = range[1];
            if (start <= left && left <= end)
                left = end + 1;
        }
        return left > right;
    }
};

int main()
{
    vector<vector<int>> ranges;
    ranges.push_back({1, 10});
    ranges.push_back({10, 20});
    int left = 1, right = 21;
    cout << Solution().isCovered(ranges, left, right) << endl;
    return 0;
}