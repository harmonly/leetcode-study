#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto &it : intervals)
        {
            int l = it[0], r = it[1];
            if (!merged.size() || merged.back()[1] < l)
                merged.push_back({l, r});
            else
                merged.back()[1] = max(merged.back()[1], r);
        }
        return merged;
    }
};