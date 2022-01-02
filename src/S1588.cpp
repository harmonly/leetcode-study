#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; i + j - 1 < n; j += 2)
                ans += accumulate(arr.begin() + i, arr.begin() + i + j, 0);
        }
        return ans;
    }

    int sumOddLengthSubarrays2(vector<int>& arr) {
        int ans = 0, n = arr.size();
        int sums[n + 1];
        sums[0] = 0;
        for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + arr[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; i + j < n; j += 2) ans += sums[i + j + 1] - sums[i];
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << Solution().sumOddLengthSubarrays2(arr) << endl;
    return 0;
}