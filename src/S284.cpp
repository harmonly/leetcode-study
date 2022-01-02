#include <bits/stdc++.h>

using namespace std;

class Iterator {
    struct Data;
    Data* data;

   public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    int next();

    bool hasNext() const;
};

class PeekingIterator : public Iterator {
   private:
    int nextElement;
    bool flag;

   public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return nextElement; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
    }

    bool hasNext() const { return flag; }
};