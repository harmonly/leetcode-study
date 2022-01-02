#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (auto& num : nums) {
            map[num]++;
            if (map[num] > n / 2) return num;
        }
        return -1;
    }

    int majorityElement2(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int& num : nums) {
            if (count == 0) candidate = num;
            if (num == candidate)
                count++;
            else
                count--;
        }
        count = 0;
        int length = nums.size();
        for (int& num : nums) {
            if (num == candidate) count++;
        }
        return count * 2 > length ? candidate : -1;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}