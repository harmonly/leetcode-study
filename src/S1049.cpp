#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        int len = stones.size();
        for (int i = 0; i < len; i++)
            sum += stones[i];
        int maxWeight = sum / 2;
        int dp[len + 1][maxWeight + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++)
        {
            for (int j = 0; j <= maxWeight; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }

        return sum - 2 * dp[len][maxWeight];
    }
};

int main()
{
    vector<int> stones = {31, 26, 33, 21, 40};
    cout << Solution().lastStoneWeightII(stones) << endl;
    return 0;
}