#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; i++)
        {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2)
            return true;
        for (int i = n; i < m; i++)
        {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - n] - 'a']--;
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }

    bool checkInclusion2(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        if (n > m)
            return false;
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i)
            --cnt[s1[i] - 'a'];
        int left = 0;
        for (int right = 0; right < m; right++)
        {
            int x = s2[right] - 'a';
            ++cnt[x];
            while (cnt[x] > 0)
            {
                --cnt[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == n)
                return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    cout << Solution().checkInclusion(s1, s2) << endl;
    return 0;
}