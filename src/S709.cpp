#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string toLowerCase(string s) {
        for (char& ch : s) ch = tolower(ch);
        return s;
    }
};