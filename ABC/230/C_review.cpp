#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
xとyが与えられたときに色を求められるかどうか？

*/

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    int h = q-p+1,  w = s-r+1;
    vector<vector<char>> ans(h, vector<char>(w, '.'));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            ll x = p+i, y = r+j;
            if(x+y == a+b || x-y == a-b) {
                ans[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}