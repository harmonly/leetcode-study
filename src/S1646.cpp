#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int getMaximumGenerated(int n) {
        if (n < 1) return 0;
        int nums[n + 1], _max = 1;
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; i++) {
            nums[i] = nums[i / 2];
            if ((i & 1) != 0) nums[i] += nums[i / 2 + 1];
            _max = max(_max, nums[i]);
        }
        return _max;
    }
};

int main() {
    cout << Solution().getMaximumGenerated(3) << endl;
    return 0;
}