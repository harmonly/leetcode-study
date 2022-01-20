#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool stoneGameIX(vector<int>& stones) {
        int nums[3] = {0, 0, 0};
        for (int i = 0; i < stones.size(); ++i) nums[stones[i] % 3]++;
        if (nums[0] % 2 == 0) return nums[1] > 0 && nums[2] > 0;
        return abs(nums[1] - nums[2]) > 2;
    }
};