#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        if (isupper(word[n - 1])) {
            for (int i = n - 2; i >= 0; i--) {
                if (islower(word[i])) return false;
            }
        } else {
            for (int i = n - 2; i >= 1; i--) {
                if (isupper(word[i])) return false;
            }
        }
        return true;
    }

    bool detectCapitalUse2(string word) {
        // 若第 1 个字母为小写，则需额外判断第 2 个字母是否为小写
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1]))
            return false;
        // 无论第 1 个字母是否大写，其他字母必须与第 2 个字母的大小写相同
        for (int i = 2; i < word.size(); i++) {
            if (islower(word[1]) ^ islower(word[i])) return false;
        }
        return true;
    }
};