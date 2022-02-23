#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    Solution(vector<int>& nums)
        : nums(nums), original(nums), rng(random_device{}()) {}

    vector<int> reset() { return original; }

    vector<int> shuffle() {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int r = i + rand() % (n - i);
            swap(nums[i], nums[r]);
        }
        return nums;
    }

    vector<int> shuffle2() {
        std::shuffle(nums.begin(), nums.end(), rng);
        return nums;
    }

   private:
    mt19937 rng;
    vector<int> nums;
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */