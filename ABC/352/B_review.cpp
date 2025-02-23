#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (n); ++i)

int main() {
    string s, t;
    cin >> s >> t;

    int si = 0; //sの何文字目？を表す変数。
    rep(i, t.size()) {
        if(s[si] == t[i]) {
            cout << i+1 << " ";
            si++;
        }
    }
    cout << endl;

    return 0;
}