#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestSubstring(string s, int k) { return dfs(s, k); }

    int dfs(string s, int k) {
        int ans = 0, n = s.length();
        if (n < 1) return ans;
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; ++i) freq[s[i] - 'a']++;
        int pos = 0;
        while (pos < n && freq[s[pos] - 'a'] >= k) ++pos;
        if (pos == n) return n;  // 不存在数量小于k的字符
        int l =
            dfs(s.substr(0, pos),
                k);  // 存在数量小于k的字符, 该字符的位置为pos, 对左半区域分治
        while (pos < n && freq[s[pos] - 'a'] < k) ++pos;  // 跳过数量小于k的字符
        int r = dfs(s.substr(pos), k);  // 对右半区域分治
        return max(l, r);  // 返回左半或右半区域的最长重复字符的长度
    }
};

int main() {
    string s = "aaacbbbbbbcaaa";
    cout << Solution().longestSubstring(s, 3) << endl;
}