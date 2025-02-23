#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false; }

// やっぱりDPはDFSをやってからこっちに来ないとしんどいな、説明するときに。

vector<vector<int>> G;
vector<int> dp;

int rec(int v) {
    if (dp[v] != -1) return dp[v]; // すでに更新済み

    int res = 0;
    for (auto nv : G[v]) {
        chmax(res, rec(nv) + 1);
    }
    return dp[v] = res;
}



int main() {
    int n, m;
    cin >> n >> m;
    G.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
    }

    // 初期化
    // 今回はn+1みたいなことは必要なくて0-indexでok
    dp.assign(n, -1);
    
    int res = 0;
    // スタート地点を0から始めてnまで考えている。全て繋がっている時は最初に代入した値
    // 例えばrec(0)のdp[0]に長さの情報が入る。
    for (int v = 0; v < n; v++) chmax(res, rec(v)); // 配列をそのまま投げると配列の一番最初の参照が渡されるはず。
    cout << res << endl;
    return 0;
}
