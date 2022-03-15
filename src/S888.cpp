#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int diff = abs(sum1 - sum2) / 2;
        if (sum1 > sum2) {
            for (auto& a : aliceSizes)
                if (binary_search(bobSizes.begin(), bobSizes.end(), a - diff))
                    return {a, a - diff};
        }
        for (auto& b : bobSizes) {
            if (binary_search(aliceSizes.begin(), aliceSizes.end(), b - diff))
                return {b - diff, b};
        }
        return {-1, -1};
    }
};