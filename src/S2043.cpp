#include <bits/stdc++.h>

using namespace std;

class Bank {
    using ll = long long;

   private:
    int n;
    vector<ll> acc;
    bool check(int account) { return account <= n; }

   public:
    Bank(vector<ll>& balance) {
        n = balance.size();
        acc.resize(n + 1);
        for (int i = 1; i <= n; ++i) acc[i] = balance[i - 1];
    }

    bool transfer(int account1, int account2, ll money) {
        if (!check(account1) || !check(account2)) return false;
        return withdraw(account1, money) && deposit(account2, money);
    }

    bool deposit(int account, ll money) {
        if (!check(account)) return false;
        acc[account] += money;
        return true;
    }

    bool withdraw(int account, ll money) {
        if (!check(account) || acc[account] < money) return false;
        acc[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */