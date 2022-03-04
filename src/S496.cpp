#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // 预处理 nums2, 使查询 nums1 的下一个更大元素时不需要遍历 nums2
    // 上述可分为两个子问题
    // 1. 如何更高效的地计算 nums2 中每个元素右边第一个更大元素
    // 2. 如何存储 1. 的子结果
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;  // 存储 nums2 每个元素右边第一个更大元素
        stack<int> st;  // 单调栈, 用于解决下一个更大元素问题
        // 倒序遍历 nums2, 并用单调栈维护当前元素右边第一个更大元素列表
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            // 弹出小于当前元素的栈顶元素,
            // 直到下一个栈顶元素大于当前元素或栈为空
            while (!st.empty() && st.top() < nums2[i]) st.pop();
            mp[num] = st.empty()
                          ? -1
                          : st.top();  // 如果栈为空, 说明没有下一个更大元素,
                                       // 不为空则有
            st.push(num);  // 压入当前元素(可能为前面元素的下一个更大元素)
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) ans.push_back(mp[nums1[i]]);
        return ans;
    }
};