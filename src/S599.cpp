#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        int sum = INT_MAX;
        for (int i = 0; i < list1.size(); ++i) mp[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i) {
            string& s = list2[i];
            if (mp.count(s)) {
                if (i + mp[s] == sum)
                    ans.push_back(s);
                else if (i + mp[s] < sum) {
                    sum = i + mp[s];
                    ans.clear();
                    ans.push_back(s);
                } else
                    break;
            }
        }
        return ans;
    }
};