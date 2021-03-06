#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k)
                    ans = max(ans, f(points[i][0], points[i][1], points[j][0],
                                     points[j][1], points[k][0], points[k][1]));
            }
        }
        return ans;
    }

    double f(int a, int b, int c, int d, int e, int f) {
        return 0.5 * abs((c - a) * (f - b) - (e - a) * (d - b));
    }
};