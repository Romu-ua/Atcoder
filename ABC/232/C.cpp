#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

Graph G_ab, G_cd;
vector<int> edge_ab, edge_cd;

void dfs(int v) {
    edge_ab[v] = true;
    edge_cd[v] = true;

}

int main() {

    // グラフなのでDFSで解けそう。
    // 同型写像をどのように解くのか？→繋がっている辺の数が一致していればその頂点同士をマッピングする。
    // 

    int n, m;
    cin >> n >> m;
    G_ab.resize(n), G_cd.resize(n);
    edge_ab.assign(n, false), edge_cd.assign(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G_ab[a].emplace_back(b);
        G_ab[b].emplace_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G_cd[a].emplace_back(b);
        G_cd[b].emplace_back(a);
    }

    // 次数チェックとサイズの確認はここで行う
    if (G_ab.size() != G_cd.size()) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> vec_size_ab(n), vec_size_cd(n);
    for (int i = 0; i < n; i++) {
        for (auto g : G_ab) {
            vec_size_ab.emplace_back(g.size());
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto g : G_cd) {
            vec_size_ab.emplace_back(g.size());
        }
    }

    sort(vec_size_ab.begin(), vec_size_ab.end());
    sort(vec_size_cd.begin(), vec_size_cd.end());
    if(vec_size_ab != vec_size_cd) { 
        cout << "No" << endl;
        return 0;
    }
    
    dfs(0);
    

    return 0;
}