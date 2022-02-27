#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> nums(26);  // 保存字符个数
        int n = s.length();
        int l = 0, r = 0, maxn = 0;  // maxn 表示前 r 个的最大重复字符数量
        while (r < n) {
            nums[s[r] - 'A']++;  // 窗口增加右边的一个字符
            maxn = max(maxn, nums[s[r] - 'A']);  // 更新最大重复字符数量
            if (r - l + 1 - maxn >
                k) {  // 如果 [l, r] 区间非最大重复字符的数量大于可以执行的次数
                      // k
                nums[s[l] - 'A']--;  // 窗口删除左边的一个字符
                l++;
            }
            r++;
        }
        return r - l;
    }
};

int main() {
    string s = "ABAA";
    int k = 0;
    cout << Solution().characterReplacement(s, k) << endl;
    return 0;
}