#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
using mint = modint998244353;

int main() {
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--, t--, x--;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<vector<vector<mint>>> dp(k + 1, vector<vector<mint>>(n, vector<mint>(2, 0)));
    dp[0][s][0] = 1;

    for (int depth = 0; depth < k; depth++) {
        for (int v = 0; v < n; v++) {
            for (int parity = 0; parity < 2; parity++) {
                for (int nv : G[v]) {
                    dp[depth + 1][nv][parity ^ (nv == x ? 1 : 0)] += dp[depth][v][parity];
                }
            }
        }
    }

    mint ans = dp[k][t][0];
    cout << ans.val() << endl;
    return 0;
}
