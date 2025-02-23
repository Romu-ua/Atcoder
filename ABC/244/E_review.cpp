#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

/*
DPかー。
見えんかった。無限に深さ優先で実装しようとしていた。
dp[k][v][i] := 頂点vにいる、k歩進んだ時、xを通った回数 % 2 がiの時、の場合の数。
かなりシンプル目なDPになっている。
*/

vector<vector<vector<mint>>> dp;

int main() {
    int n, m, K, s, t, x;
    cin >> n >> m >> K >> s >> t >> x;
    --s, --t, --x;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }   

    dp.assign(K+1, vector<vector<mint>>(n+1, vector<mint>(2, 0)));
    dp[0][s][0] = 1;
    for (int k = 0; k < K; k++) {
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < 2; i++) {
                for (int u : G[v]) {
                    int nk = k + 1, nv = u, ni = i;
                    if (u == x) ni ^= 1; // niが１なら0にして、1なら0にする。排他的論理和。
                    dp[nk][nv][ni] += dp[k][v][i];
                }
            }
        }
    }

    mint ans = dp[K][t][0];
    cout << ans.val() << endl;
    return 0;
}