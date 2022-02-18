#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degrees(n + 2);
        for (int i = 0; i < n; ++i) {
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        for (int i = 1; i <= n + 1; ++i)
            if (degrees[i] == n) return i;
        return 0;
    }

    int findCenter2(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        int u = edges[1][0], v = edges[1][1];
        if (a == u || a == v) return a;
        if (b == u || b == v) return b;
        return a;
    }
};