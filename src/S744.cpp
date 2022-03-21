#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mn = 99;
        char ans = ' ', fi = 'z';
        for (auto& letter : letters) {
            if (target == letter) continue;
            int d = letter - target;
            if (d < mn && d > 0) {
                mn = d;
                ans = letter;
            }
            if (letter < fi) fi = letter;
        }
        if (ans == ' ') ans = fi;
        return ans;
    }
};

class Solution2 {
   public:
    int vis[26];

    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto& letter : letters) vis[letter - 'a'] = 1;
        while (true) {
            ++target;
            if (target > 'z') return letters[0];
            if (vis[target - 'a']) return target;
        }
        return letters[0];
    }
};

class Solution3 {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (auto& letter : letters)
            if (letter > target) return letter;
        return letters[0];
    }
};

class Solution4 {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return letters[l % n];
    }
};