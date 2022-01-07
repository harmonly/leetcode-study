#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) heap.pop();
        }
        return heap.top();
    }
};