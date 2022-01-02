#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> left, star;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == '*')
                star.push(i);
            else {
                if (left.empty() && star.empty()) return false;
                if (!left.empty())
                    left.pop();
                else
                    star.pop();
            }
        }
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }

    bool checkValidString2(string s) {
        int l = 0, h = 0;
        for (auto& ch : s) {
            if (ch == '(') { 
                l++;
                h++;
            } else if (ch == ')') {
                l = max(l - 1, 0);
                h--;
                if (h < 0) return 0;
            } else {
                l = max(l - 1, 0);
                h++;
            }
        }
        return l == 0;
    }
};