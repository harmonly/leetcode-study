#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int ans = 0, right = -1;
        unordered_set<char> set;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                set.erase(s[i - 1]);
            while (right + 1 < n && !set.count(s[right + 1]))
                set.insert(s[right++ + 1]);
            ans = max(ans, right - i + 1);
        }
        return ans;
    }

    int lengthOfLongestSubstring2(string s)
    {
        int set[128];
        for (int i = 0; i < 128; i++)
            set[i] = -1;

        int n = s.length();
        int res = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            int index = s[i];
            start = max(start, set[index] + 1);
            res = max(res, i - start + 1);
            set[index] = i;
        }
        return res;
    }
};