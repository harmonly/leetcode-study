#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> ans;
        while (label > 1)
        {
            ans.push_back(label);
            int n = log(label) / log(2);

            int parent = pow(2, n) - 1 + pow(2, n - 1) - label / 2;
            label = parent;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int label = 14;
    printf("%d\n", Solution().pathInZigZagTree(label));
    return 0;
}