#include <bits/stdc++.h>

using namespace std;

class StockPrice {
   public:
    StockPrice() : cur(0) {}

    void update(int timestamp, int price) {
        cur = max(cur, timestamp);
        int prevPrice = mp.count(timestamp) ? mp[timestamp] : 0;
        mp[timestamp] = price;
        if (prevPrice > 0) {
            auto it = prices.find(prevPrice);
            if (it != prices.end()) prices.erase(it);
        }
        prices.emplace(price);
    }

    int current() { return mp[cur]; }

    int maximum() { return *prices.rbegin(); }

    int minimum() { return *prices.begin(); }

   private:
    unordered_map<int, int> mp;
    multiset<int> prices;
    int cur;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */