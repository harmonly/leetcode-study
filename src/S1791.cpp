#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        int u = edges[1][0], v = edges[1][1];
        if (a == u || a == v) return a;
        if (b == u || b == v) return b;
        return a;
    }
};