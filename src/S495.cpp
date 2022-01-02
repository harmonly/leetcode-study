#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration;
        int n = timeSeries.size();
        int time = timeSeries[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int diff = time - timeSeries[i];
            ans += diff > duration ? duration : diff;
            time = timeSeries[i];
        }
        return ans;
    }
};