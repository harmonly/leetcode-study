#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<int> ans;
    
    vector<int> lexicalOrder(int n) {
        this->n = n;
        for (int i = 1; i < 10; ++i) dfs(i);
        return ans;
    }

    void dfs(int cur) {
        if (cur > n) return;
        ans.push_back(cur);
        for (int i = 0; i < 10; ++i)
            dfs(cur * 10 + i);
    }
};