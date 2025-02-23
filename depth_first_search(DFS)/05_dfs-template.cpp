//DFSのテンプレート
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true;

    for (auto next_v : G[v]){
        if (seen[next_v]) continue; //探索済みならスルー
        dfs(G, next_v);
    }
}


int main() {
    //頂点数と辺数
    int N, M;
    cin >> N >> M;
    
    //グラフの入力受け取り(無向グラフを想定)
    //隣接リスト表現の方が多くの場合で効率の良い実装ができるらしい、
    Graph G(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //頂点0をスタートとした探索
    seen.assign(N, false);
    dfs(G, 0);

}