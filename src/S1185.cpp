#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string dayOfTheWeek(int day, int month, int year) {
        int dayOfTheYear = 0;
        for (int i = 1971; i < year; ++i) dayOfTheYear += isLeap(i) ? 366 : 365;
        monthDays[1] += isLeap(year) ? 1 : 0;
        for (int i = 0; i < month - 1; i++) dayOfTheYear += monthDays[i];
        dayOfTheYear += day;
        return weeks[(dayOfTheYear + 4) % 7];
    }

   private:
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weeks[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"};
    bool isLeap(int year) {
        return (year % 400 == 0) || ((year % 4 == 0) & year % 100 != 0);
    }
};