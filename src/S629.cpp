#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto& word : words) mp[word]++;
        vector<pair<string, int>> vec;
        for (auto& it : mp) vec.push_back(make_pair(it.first, it.second));
        sort(vec.begin(), vec.end(),
             [&](pair<string, int> a, pair<string, int> b) {
                 if (a.second == b.second) return a.first < b.first;
                 return a.second > b.second;
             });
        vector<string> ans;
        for (int i = 0; i < min((int)vec.size(), k); ++i)
            ans.push_back(vec[i].first);
        return ans;
    }
};

class Solution2 {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words) cnt[word]++;
        auto cmp = [&](const pair<string, int> a, const pair<string, int> b) {
            return a.second == b.second ? a.first < b.first
                                        : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(cmp)>
            que(cmp);
        for (auto& it : cnt) {
            que.emplace(it);
            if (que.size() > k) que.pop();
        }
        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = que.top().first;
            que.pop();
        }
        return ans;
    }
};