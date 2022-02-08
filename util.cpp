#include <bits/stdc++.h>

using namespace std;

string bracket2Brace(string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '[')
            s[i] = '{';
        else if (s[i] == ']')
            s[i] = '}';
    }
    return s;
}

string convertGrid(string s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '[')
            s[i] = '{';
        else if (s[i] == ']')
            s[i] = '}';
        else if (s[i] == '\"')
            s[i] = '\'';
    }
    return s;
}

int main() {
    int op = -1;
    cout << "------------------" << endl
         << "1. 中括号转大括号" << endl
         << "2. 二维字符数组" << endl
         << "请输入操作数: ";
    cin >> op;
    switch (op) {
        case 1: {
            cout << "输入待转换字符串: " << endl;
            string s;
            cin >> s;
            cout << bracket2Brace(s) << endl;
            cout << "转换完成" << endl;
            break;
        }
        case 2: {
            cout << "输入待转换字符串: " << endl;
            string s;
            cin >> s;
            cout << convertGrid(s) << endl;
            cout << "转换完成" << endl;
            break;
        }
        default:
            break;
    }
    return 0;
}