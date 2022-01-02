#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) return 0;
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0;
        while (nums[left] == numsSorted[left]) left++;
        int right = nums.size() - 1;
        while (nums[right] == numsSorted[right]) right--;
        return right - left;
    }

    int findUnsortedSubarray2(vector<int>& nums) {
        int n = nums.size();
        int _min = INT_MAX, left = -1;
        int _max = INT_MIN, right = -1;
        for (int i = 0; i < n; i++) {
            if (_min < nums[n - i - 1])
                left = n - i - 1;
            else
                _min = nums[n - i - 1];

            if (_max > nums[i])
                right = i;
            else
                _max = nums[i];
        }

        return left == -1 ? 0 : right - left + 1;
    }
};

int main() {
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << Solution().findUnsortedSubarray2(nums) << endl;
    return 0;
}