#include <bits/stdc++.h>
using namespace std;

/*
Nが小さいのでN^3でも間に合う。
つまり、３角形の判定条件のみが重要になる。
つまり、３点が一直線乗に並んでいるかどうかの判定。
やり方。
1. 適当な一点を決めて、他の２点の直線の傾きが一致しているかどうかを判定する。
ポイントとして、絶対をとって比較はできない。
しかし、分数の比較はむずい。また、xが０になることもある。
つまり、移行して、式を変形すると、外積が0になる式と一緒になる。

2. 外積を求める。
式としては同じになる。
外積 = 2 ✖️ 符号付き面積


*/

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                long long xa = x[j] - x[i];
                long long ya = y[j] - y[i];
                long long xb = x[k] - x[i];
                long long yb = y[k] - y[i];
                if(xa*yb != xb*ya) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}