#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool winnerOfGame(string colors) {
        int n = colors.length(), ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A' && colors[i + 1] == 'A' &&
                colors[i - 1] == 'A')
                ++ans;
            if (colors[i] == 'B' && colors[i + 1] == 'B' &&
                colors[i - 1] == 'B')
                --ans;
        }
        return ans > 0;
    }
};