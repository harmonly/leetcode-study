#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> nums(26, 0);
        for (auto& ch : text) ++nums[ch - 'a'];
        return min({nums['b' - 97], nums['a' - 'a'], nums['l' - 'a'] >> 1, nums['o' - 'a'] >> 1, nums['n' - 'a']});
    }
};