#include <bits/stdc++.h>
using namespace std;


vector<bool> seen;
vector<int> result;

void dfs(const vector<vector<int>> &G, int v) {
    seen[v] = true;
    result.emplace_back(v);
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}


int main() {
    int n, q;
    cin >> n >> q;

    //有向グラフであることはわかった。
    vector<vector<int>> vec(n);

    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        
        if(a == 1) {
            int x, y;
            cin >> x >> y;
            vec[y].emplace_back(x);
        }
        if(a == 2) {

        }
        if(a == 3) {
            int x;
            cin >> x;
            //深さ優先探索で出力をゲット。
            //矢印の根に戻る関数と根から矢印の先を全て出力する関数の２つが必要？
            dfs(vec, x);
        }
    }
    return 0;
}