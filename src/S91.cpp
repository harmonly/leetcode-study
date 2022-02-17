#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i > 1 && s[i - 2] != '0' &&
                (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }

    int numDecodings2(string s) {
        int n = s.length();
        int a = 0, b = 1, c;  // a = f[i-2], b = f[i-1], c = f[i]
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') c += b;
            if (i > 1 && s[i - 2] != '0' &&
                (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26)
                c += a;
            a = b, b = c;
        }
        return c;
    }
};

int main() {
    cout << Solution().numDecodings("2101") << endl;
    return 0;
}