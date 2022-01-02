#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) ret++;
        }
        return ret;
    }

    int hammingWeight2(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= (n - 1);
            ret++;
        }
        return ret;
    }
};

int main() {
    cout << Solution().hammingWeight2(7) << endl;
    return 0;
}