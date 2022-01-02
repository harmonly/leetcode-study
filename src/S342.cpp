#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().isPowerOfFour(n) << endl;
    return 0;
}