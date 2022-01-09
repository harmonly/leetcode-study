#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int max_time = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            char ch = keysPressed[i];
            int time = releaseTimes[i] - releaseTimes[i - 1];
            if (time > max_time) {
                max_time = time;
                ans = ch;
            } else if (time == max_time) {
                ans = max(ans, ch);
            }
        }
        return ans;
    }
};