#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        int n = s.length();
        for (auto &ch : s) map[ch]++;
        vector<pair<char, int>> vec;
        for (auto &it : map) vec.emplace_back(it);
        sort(vec.begin(), vec.end(),
             [](const pair<char, int> &a, const pair<char, int> &b) {
                 return a.second > b.second;
             });
        string ret;
        for (auto &it : vec)
            for (int i = 0; i < it.second; i++) ret.push_back(it.first);
        return ret;
    }

    string frequencySort2(string s) {
        unordered_map<char, int> map;
        for (auto &ch : s) map[ch]++;
        sort(s.begin(), s.end(), [&](const char &a, const char &b) {
            return map[a] == map[b] ? a > b : map[a] > map[b];
        });
        return s;
    }
};

class Solution2 {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0, n = s.length();
        for (auto &ch : s) maxFreq = max(maxFreq, ++mp[ch]);
        vector<string> buckets(maxFreq + 1);
        for (auto &it : mp) buckets[it.second].push_back(it.first);
        string ans;
        for (int i = maxFreq; i > 0; --i) {
            string &bucket = buckets[i];
            for (auto &ch : bucket)
                for (int k = 0; k < i; ++k) ans.push_back(ch);
        }
        return ans;
    }
};