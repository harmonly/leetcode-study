#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        int a[2001];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < arr.size(); ++i) a[arr[i]] = 1;
        int idx = 1, cnt = 0;
        for (;;) {
            if (!a[idx++]) cnt++;
            if (cnt == k) break;
        }
        return idx - 1;
    }
};