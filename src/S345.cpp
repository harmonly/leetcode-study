#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        string alpha = "aeiouAEIOU";
        while (i < j) {
            while (i < n && alpha.find(s[i]) == -1) i++;
            while (j > 0 && alpha.find(s[j]) == -1) j--;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};