#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
using mint = modint998244353;

// dfsで枝狩りが必要ってところまでは行ったが、具体的にどのように実装すれば良いのかわからなかった。

mint dfs(int v, Graph& G, int depht, int k, int t, int cnt_x, int x) {
    if (v == x) cnt_x++;

    if (depht == k && v == t && (cnt_x % 2) == 0) return mint(1);
    if (depht == k && v != t) return mint(0);

    mint ans = 0;
    for (auto nv : G[v]) {
        ans += dfs(nv, G, depht+1, k, t, cnt_x, x);
    } 
    return ans;
}

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

    // グラフにおいて、取りうる遷移の全探索？計算量的に無理
    // 深さを持たせて深さ優先探索？
    // 頂点数N　* 深さK * 辺の個数M の大きさの木になる。
    mint ans = 0;
    int cnt_x = 0;
    ans = dfs(s, G, 0, k, t, cnt_x, x);

    cout << ans.val() << endl;
    return 0;
}