#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> delta;
    int n, zero;
    int ans = 0, cnt = 0;

   public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        delta.resize(n);
        zero = n;
        this->n = n;
        dfs(requests, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& requests, int idx) {
        if (idx == requests.size()) {
            if (zero == n) ans = max(ans, cnt);
            return;
        }
        // 不选择 requests[idx]
        dfs(requests, idx + 1);

        // 选择 requests[idx]
        int f = requests[idx][0], t = requests[idx][1];
        int z = zero;
        ++cnt;
        zero -= delta[f] == 0;
        --delta[f];  // f 房子人数减一
        zero += delta[f] == 0;

        zero -= delta[t] == 0;
        ++delta[t];  // t 房子人数加一
        zero += delta[t] == 0;

        dfs(requests, idx + 1);
        // 回溯
        ++delta[f];
        --delta[t];
        --cnt;
        zero = z;
    }
};