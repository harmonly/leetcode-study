#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        const int MOD = (int)1e9 + 7;
        int len = group.size();
        int dp[len + 1][n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;

        for (int i = 1; i <= len; i++)
        {
            int member = group[i - 1], earn = profit[i - 1];
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= minProfit; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k] % MOD;
                    if (j >= member)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - member][max(0, k - earn)]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j <= n; j++)
            ans = (ans + dp[len][j][minProfit]) % MOD;
        return ans;
    }

    int profitableSchemes2(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int dp[n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        int len = group.size(), MOD = (int)1e9 + 7;
        for (int i = 1; i <= len; i++)
        {
            int member = group[i - 1], earn = profit[i - 1];
            for (int j = n; j >= member; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                    dp[j][k] = (dp[j][k] + dp[j - member][max(0, k - earn)]) % MOD;
            }
        }

        return dp[n][minProfit];
    }
};

int main()
{
    int n = 10, minProfit = 5;
    vector<int> group = {2, 3, 5};
    vector<int> profit = {6, 7, 8};
    cout << Solution().profitableSchemes(n, minProfit, group, profit) << endl;
    return 0;
}