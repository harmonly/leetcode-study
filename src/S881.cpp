#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int light = 0, heavy = people.size() - 1;
        int ans = 0;
        while (light <= heavy) {
            if (people[light] + people[heavy] > limit)
                heavy--;
            else {
                light++;
                heavy--;
            }
            ans++;
        }
        return ans;
    }
};