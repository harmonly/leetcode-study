#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef int _ct;
_ct gcd(_ct a, _ct b) { return b ? gcd(b, a % b) : a; }

class Solution {
   public:
    long long countPairs(vector<int>& nums, int k) {
        vector<int> div;
        for (int d = 1; d * d <= k;
             ++d) {  // 预处理 k 的所有因子, 83160 的因子最多, 有 128个
            if (k % d == 0) {
                div.push_back(d);
                if (d * d < k) div.push_back(k / d);
            }
        }
        ll ans = 0;
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ans += cnt[k / gcd(num, k)];
            for (int d : div)
                if (num % d == 0)
                    ++cnt[d];  // 遍历当前所有因子, 如果 d 是 num 的因子, 则
                               // cnt[d] 的数量 +1
        }
        return ans;
    }
};

// nums[i] * nums[j] / k = d
// nums[i] = d * k / nums[j] = d * k / gcd(k, nums[j]);