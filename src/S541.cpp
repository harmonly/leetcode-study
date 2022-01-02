#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k)
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        return s;
    }
};

int main() {
    string s = "abcd";
    int k = 2;
    cout << Solution().reverseStr(s, k) << endl;
    return 0;
}