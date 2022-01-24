#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> used(n);
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u < 0 || u > n - 1) continue;
            if (arr[u] == 0) return true;
            if (used[u]) continue;
            used[u] = true;
            q.push(u + arr[u]);
            q.push(u - arr[u]);
        }
        return false;
    }
};

int main() {
    vector<int> arr{4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    cout << Solution().canReach(arr, start) << endl;
    return 0;
}