#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        vector<int> path;
        return backtrack(nums, path, 0);
    }

    int triangleNumber2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    } else
                        right = mid - 1;
                }
                ans += k - j;
            }
        }
        return ans;
    }

   private:
    int backtrack(vector<int>& nums, vector<int>& path, int index) {
        if (path.size() == 3) return isTriangle(path) ? 1 : 0;
        int res = 0;
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res += backtrack(nums, path, i + 1);
            path.pop_back();
        }

        return res;
    }

    bool isTriangle(vector<int> triangle) {
        int a = triangle[0], b = triangle[1], c = triangle[2];
        if (a + b > c && a + c > b && b + c > a) return true;
        return false;
    }
};