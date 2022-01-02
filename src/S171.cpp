#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (auto c : columnTitle)
            ans = ans * 26 - 'A' + c + 1;
        return ans;
    }
};

int main()
{
    string columnTitle = "Z";
    cout << Solution().titleToNumber(columnTitle) << endl;
    return 0;
}