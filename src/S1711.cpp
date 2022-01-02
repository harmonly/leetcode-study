#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &deliciousness)
    {
        const int MOD = 1000000007;
        int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
        int maxSum = maxVal * 2;
        int pairs = 0;
        unordered_map<int, int> map;
        int n = deliciousness.size();
        for (auto &val : deliciousness)
        {
            for (int sum = 1; sum <= maxSum; sum <<= 1)
            {
                int count = map.count(sum - val) ? map[sum - val] : 0;
                pairs = (pairs + count) % MOD;
            }
            map[val]++;
        }
        return pairs % MOD;
    }
};