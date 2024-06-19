#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// グラフはDFSでも参照で渡しているから違和感ないけど、dpも参照で渡しているとめんどくさいのでグローバルに書いてしまう。
vector<int> dp;

int rec(vector<vector<int>>& G, int v) {
    //　すでに更新済みなら、その時の深さを返す。
    if (dp[v] != -1) return dp[v];

    int res = 0;
    for (auto nv : G[v]) {
        chmax(res, rec(G, nv) + 1);
    }
    return dp[v] = res;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].emplace_back(b);
    }

    // 初期化
    dp.assign(N, -1);

    int res = 0;
    for (int v = 0; v < N; v++) {
        chmax(res, rec(G, v));
    }

    cout << res << endl;
    return 0;
}