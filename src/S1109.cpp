#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto& booking : bookings) {
            int first = booking[0], last = booking[1], seats = booking[2];
            ans[first - 1] += seats;
            if (last >= n) continue;
            ans[last] -= seats;
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
        return ans;
    }
};