#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> mp{{')', '('}, {']', '['}, {'}', '{'}};
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else {
                if (st.empty() || st.top() != mp[ch]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};