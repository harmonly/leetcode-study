#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> ms;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
            if (i >= k - 1) {
                auto it = ms.begin();
                advance(it, k / 2);
                ans.push_back((*it + *prev(it, (1 - k % 2))) / 2);
            }
        }
        return ans;
    }

    /*
    作者：leck
    链接：https://leetcode-cn.com/problems/sliding-window-median/solution/wo-jue-de-wo-de-ti-jie-neng-chong-dao-qi-nu33/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
         tree_order_statistics_node_update>
        t;
    vector<double> medianSlidingWindow2(vector<int>& nums, int k) {
        queue<pair<int, int>> q;
        vector<double> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(make_pair(nums[i], i));
            t.insert(make_pair(nums[i], i));
            if (q.size() >= k) {
                long x = (*t.find_by_order(k / 2)).first;
                long y = (*t.find_by_order((k - 1) / 2)).first;
                ans.push_back((x + y) / 2.0);
                t.erase(q.front());
                q.pop();
            }
        }
        return ans;
    }
};