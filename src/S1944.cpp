#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() < heights[i]) {
                ans[i]++;
                st.pop();
            }
            if (!st.empty()) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> heights{10, 6, 8, 5, 11, 9};
    Solution().canSeePersonsCount(heights);
    return 0;
}