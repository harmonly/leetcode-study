#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int n = arr.size(); n > 1; --n) {
            int idx = max_element(arr.begin(), arr.begin() + n) -
                      arr.begin();  // 最大元素位置
            if (idx == n - 1) continue;  // 如果最大元素已经在最后一位则继续
            if (idx != 0) {  // 如果最大元素不在第一位, 即不用翻转[0, 0]
                reverse(arr.begin(),
                        arr.begin() + idx + 1);  // 将最大的元素翻转到第一位
                ans.push_back(idx + 1);  // idx + 1 为选择的坚果排序位置
            }
            reverse(
                arr.begin(),
                arr.begin() + n);  // 最大的元素已经在第一位了, 直接整个数组翻转
            ans.push_back(n);  // 翻转整个数组, n 为选择的坚果排序位置
        }
        return ans;
    }
};