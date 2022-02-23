#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n != 1) {
            st.insert(n);
            int cur = 0;
            while (n) {
                cur += (n % 10) * (n % 10);
                n /= 10;
            }
            if (st.find(cur) != st.end()) return false;
            n = cur;
        }
        return true;
    }

    bool isHappy2(int n) {
        int slow = n;
        int fast = getNext(n);
        while (slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }

    int getNext(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};