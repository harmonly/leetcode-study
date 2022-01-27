#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countValidWords(string sentence) {
        int n = sentence.length();
        int l = 0, r = 0;
        int ans = 0;
        string slice(sentence);
        while (true) {
            while (l < n && sentence[l] == ' ') l++;
            if (l >= n) break;
            r = l + 1;
            while (r < n && sentence[r] != ' ') r++;
            if (isValid(slice.substr(l, r - l))) ans++;
            l = r + 1;
        }
        return ans;
    }

    bool isValid(string word) {
        int n = word.length();
        bool has_hyphens = false;
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (isdigit(ch))
                return false;
            else if (ch == '-') {
                if (has_hyphens || i == 0 || i == n - 1 ||
                    !islower(word[i - 1]) || !islower(word[i + 1]))
                    return false;
                has_hyphens = true;
            } else if (ch == '!' || ch == '.' || ch == ',')
                if (i != n - 1) return false;
        }
        return true;
    }
};

int main() {
    string sentence = "a-b";
    cout << Solution().countValidWords(sentence) << endl;
    return 0;
}