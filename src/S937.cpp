#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](string a, string b) {
            int ia = a.find_first_of(' ');
            int ib = b.find_first_of(' ');
            bool da = isdigit(a[ia + 1]);
            bool db = isdigit(b[ib + 1]);
            if (da && db) return false;
            if (!da && !db) {
                string ca = a.substr(ia + 1);
                string cb = b.substr(ib + 1);
                if (ca != cb) return ca < cb;
                return a < b;
            }
            return da ? false : true;
        });
        return logs;
    }
};