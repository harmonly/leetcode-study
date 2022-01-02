#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)),
            day = stoi(date.substr(8));
        int calendar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isleap(year)) calendar[1] = 29;
        int ans = day;
        for (int i = 1; i < month; i++) ans += calendar[i - 1];
        return ans;
    }

    bool isleap(int year) {
        return ((year % 4 == 0 && year % 100 != 0) ||
                (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0);
    }
};