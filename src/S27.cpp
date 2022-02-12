#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), cnt = 0;
        for (int num : nums) {
            if (num != val) nums[cnt++] = num;
        }
        return cnt;
    }

    int removeElement2(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        for (int i = 0; i <= j; ++i) {
            if (nums[i] == val) swap(nums[i--], nums[j--]);
        }
        return ++j;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << Solution().removeElement(nums, val) << endl;
    return 0;
}