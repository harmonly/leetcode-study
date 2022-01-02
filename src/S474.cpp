#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> getZerosOnes(string &str)
    {
        vector<int> zerosOnes(2);
        int len = str.length();
        for (int i = 0; i < len; i++)
            zerosOnes[str[i] - '0']++;

        return zerosOnes;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        int dp[len + 1][m + 1][n + 1];
        //将dp内的值设置为0
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= len; i++)
        {
            vector<int> zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[len][m][n];
    }
};