#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;

        while (s[index] == ' ') index--;
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};