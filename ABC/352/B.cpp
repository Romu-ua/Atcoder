#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    bool flag = false;
    int j = 0;

    rep(i, t.length()) {
        char ch;
        ch = s[i];
        if(s[j] == t[i]) {
            cout << i+1 << " ";
            j++;
        }
    }
    
    return 0;
}