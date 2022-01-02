#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for (auto& path : paths) mp[path[0]] = path[1];
        string ans = paths[0][0];
        while (mp.count(ans)) ans = mp[ans];
        return ans;
    }
};