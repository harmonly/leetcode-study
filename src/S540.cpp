#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid < r && nums[mid] == nums[mid + 1]) --mid;
            int a = mid - l + 1;
            if (a & 1)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }

    int singleNonDuplicate2(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] != nums[mid ^ 1])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};