#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m-- + n-- - 1;
        while (m >= 0 && n >= 0)
            nums1[tail--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        while (n >= 0) nums1[tail--] = nums2[n--];
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    Solution().merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    for (int i = 0; i < nums1.size(); ++i) cout << nums1[i] << " ";
    return 0;
}