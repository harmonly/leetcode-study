#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

    void dfs(int index, int n, int k) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i <= n; i++) {
            path.push_back(i);
            dfs(i + 1, n, k);
            path.pop_back();
        }
    }
};