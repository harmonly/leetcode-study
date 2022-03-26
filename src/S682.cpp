#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (auto& s : ops) {
            if (s == "C")
                v.pop_back();
            else if (s == "D")
                v.push_back(v.back() * 2);
            else if (s == "+")
                v.push_back(v[v.size() - 2] + v.back());
            else
                v.push_back(stoi(s));
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};