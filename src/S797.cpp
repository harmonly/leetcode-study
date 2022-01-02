#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        int n = graph.size();
        q.push({0});
        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            for (int i = 0; i < graph[path[path.size() - 1]].size(); i++) {
                path.push_back(graph[path[path.size() - 1]][i]);
                if (path[path.size() - 1] == n - 1) res.push_back(path);
                q.push(path);
                path.pop_back();
            }
        }
        return res;
    }
};