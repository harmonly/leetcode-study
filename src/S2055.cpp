#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> pre(n), left(n), right(n), ans;
        pre[0] = s[0] == '*', left[n - 1] = -1, right[0] = -1;
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + (s[i] == '*');
            right[i] = s[i] == '|' ? i : right[i - 1];
            left[n - i - 1] = s[n - i - 1] == '|' ? n - i - 1 : left[n - i];
        }
        for (int i = 0; i < queries.size(); ++i) {
            int l = left[queries[i][0]], r = right[queries[i][1]];
            int t = 0;
            if (l != -1 && r != -1 && r > l) t = pre[r] - pre[l];
            ans.push_back(t);
        }
        return ans;
    }
};