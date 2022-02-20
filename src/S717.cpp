#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), idx = 0;
        while (idx < n - 1) idx += bits[idx] + 1;
        return idx == n - 1;
    }
};