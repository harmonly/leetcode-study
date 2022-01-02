#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k = minutesToTest / minutesToDie;
        int pigs = ceil(log(buckets) / log(k + 1));
        return pigs;
    }
};