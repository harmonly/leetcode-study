#include <bits/stdc++.h>

using namespace std;

class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to
    // it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
   public:
    int idx = 0;

    NestedInteger deserialize(string s) {
        if (s[idx] == '[') {
            ++idx;
            NestedInteger ni;
            while (s[idx] != ']') {
                ni.add(deserialize(s));
                idx += s[idx] == ',';
            }
            ++idx;
            return ni;
        } else {
            int neg = 1;
            if (s[idx] == '-') {
                neg = -1;
                ++idx;
            }
            int t = 0;
            while (idx < s.length() && isdigit(s[idx]))
                t = t * 10 + s[idx++] - '0';
            return NestedInteger(t * neg);
        }
    }
};