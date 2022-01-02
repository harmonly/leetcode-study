#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans(k);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) ans[i] = arr[i];
        return ans;
    }

    vector<int> smallestK2(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) return vec;
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) Q.push(arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[k - i - 1] = Q.top();
            Q.pop();
        }
        return vec;
    }
};