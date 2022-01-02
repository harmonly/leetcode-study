#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q;
        for (int i = 0; i < stones.size(); i++)
            q.push(stones[i]);
        while (q.size() > 1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x != y)
                q.push(y - x);
        }

        return q.empty() ? 0 : q.top();
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << Solution().lastStoneWeight(stones) << endl;
    return 0;
}