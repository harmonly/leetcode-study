#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> map;
        int n = s.length();
        for (auto &ch : s)
            map[ch]++;
        vector<pair<char, int>> vec;
        for (auto &it : map)
            vec.emplace_back(it);
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
             { return a.second > b.second; });
        string ret;
        for (auto &it : vec)
            for (int i = 0; i < it.second; i++)
                ret.push_back(it.first);
        return ret;
    }

    string frequencySort2(string s)
    {
        unordered_map<char, int> map;
        for (auto &ch : s)
            map[ch]++;
        sort(s.begin(), s.end(), [&](const char &a, const char &b)
             { return map[a] == map[b] ? a > b : map[a] > map[b]; });
        return s;
    }
};