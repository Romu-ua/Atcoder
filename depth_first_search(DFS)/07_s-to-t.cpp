//sからtに辿り着けるか？
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(Graph &G, int v){
    seen[v] = true;

    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}


int main() {
    //頂点数、辺数、sとt
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    //頂点sをスタートとした探索
    seen.assign(N, false);
    dfs(G, s);

    //t に辿り着けるけかどうか
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}