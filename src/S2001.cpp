#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    using LL = long long;
    int gcd(int a, int b) {
        int r;
        while (b > 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

   public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        LL ans = 0;
        unordered_map<double, LL> mp;
        for (auto& r : rectangles) mp[(r[0] * 1.0) / r[1]]++;
        for (auto& it : mp) ans += it.second * (it.second - 1) / 2;
        return ans;
    }

    long long interchangeableRectangles2(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        LL ans = 0;
        for (auto& r : rectangles) {
            int g = gcd(r[0], r[1]);
            r[0] /= g;
            r[1] /= g;
            ans += mp[{r[0], r[1]}];
            mp[{r[0], r[1]}]++;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> rectangles{{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    cout << Solution().interchangeableRectangles2(rectangles) << endl;
    return 0;
}