#include <bits/stdc++.h>

using namespace std;

class Solution {
    int getMinutes(string& t) {
        return (int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 +
               int(t[3] - '0') * 10 + int(t[4] - '0');
    }

   public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int t0 = getMinutes(timePoints[0]);
        int pre = t0;
        for (int i = 1; i < timePoints.size(); ++i) {
            int minutes = getMinutes(timePoints[i]);
            ans = min(ans, minutes - pre);
            pre = minutes;
        }
        ans = min(ans, t0 + 24 * 60 - pre);
        return ans;
    }

    int findMinDifference2(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 24 * 60) return 0;
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int t0 = getMinutes(timePoints[0]);
        int pre = t0;
        for (int i = 1; i < n; ++i) {
            int time = getMinutes(timePoints[i]);
            ans = min(ans, time - pre);
            pre = time;
        }
        ans = min(ans, t0 + 24 * 60 - pre);
        return ans;
    }
};

int main() {
    vector<string> timePoints = {"23:59", "00:00"};
    cout << Solution().findMinDifference(timePoints) << endl;
    return 0;
}