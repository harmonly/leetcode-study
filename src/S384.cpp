#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        copy(nums.begin(), nums.end(), original.begin());
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle() {
        vector<int> shuffled = vector<int>(nums.size());
        list<int> lst(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = rand() % (lst.size());
            auto it = lst.begin();
            advance(it, j);
            shuffled[i] = *it;
            lst.erase(it);
        }
        copy(shuffled.begin(), shuffled.end(), nums.begin());
        return nums;
    }

    vector<int> shuffle2() {
        for (int i = 0; i < nums.size(); i++) {
            int j = i + rand() % (nums.size() - i);
            swap(nums[i], nums[j]);
        }
        return nums;
    }

   private:
    vector<int> nums;
    vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */