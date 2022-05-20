#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int, less<int>> mp;
        for (int i = 0; i < intervals.size(); ++i)
            mp.insert(make_pair(intervals[i][0], i));
        vector<int> ans;
        for (auto& interval : intervals) {
            auto it = mp.lower_bound(interval[1]);
            if (it != mp.end())
                ans.push_back((*it).second);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};