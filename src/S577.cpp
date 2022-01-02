#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        s.push_back(' ');
        string res, tmp;
        for (int i = 0; i <= n; i++)
        {
            if (s[i] == ' ')
            {
                reverse(tmp.begin(), tmp.end());
                tmp.push_back(' ');
                res += tmp;
                tmp = "";
                continue;
            }
            tmp.push_back(s[i]);
        }
        res.pop_back();
        return res;
    }

    string reverseWords(string s)
    {
        int length = s.length();
        int i = 0;
        while (i < length)
        {
            int start = i;
            while (i < length && s[i] != ' ')
                i++;

            int left = start, right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < length && s[i] == ' ')
                i++;
        }
        return s;
    }
};

int main()
{
    string s = "Let's take LeetCode contest";
    cout << Solution().reverseWords(s) << endl;
    return 0;
}