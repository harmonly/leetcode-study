#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthLongestPath(string input) {
        int n = input.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            string file;
            int level = 0;
            bool isfile = false;
            while (j < n && input[j] != '\n') {
                if (input[j] == '\t')
                    ++level;
                else
                    file += input[j];
                if (input[j] == '.') isfile = true;
                ++j;
            }
            if (isfile)
                ans = max(ans, level + mp[level - 1] + (int)file.length());
            else
                mp[level] = file.length() + mp[level - 1];
            i = j;
        }
        return ans;
    }
};