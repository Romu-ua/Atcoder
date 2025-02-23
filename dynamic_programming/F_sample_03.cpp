#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false; }

// 繋がっているかどうかでグラフを作って深さ優先でもできそう。

double distance(int x, int y) {
    double sq = sqrt(pow(x, 2) + pow(y, 2));
    return sq;
}


int main() {
    while(true) {
        int n, m;
        cin >> n;
        if (n = 0) break;
        vector<int> b(n), x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i] >> x[i] >> y[i];
        }
        cin >> m;
        vector<int> s(m), g(m);
        for (int i = 0; i < m; i++) {
            cin >> s[i] >> g[i];
        }

        // DPテーブル 要素は距離。縦横は建物番号。
        vector<vector<int>> dp(101, vector<int>(101, 0));

        // DPループ 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance(x[i], y[i]) <= 50) dp[b[i]]
            }
        }

        // 出力
        for (int i = 0; i < m; i++) {
            cout << dp[s[i]][g[i]] << endl;
        }
    }


    return 0;
}