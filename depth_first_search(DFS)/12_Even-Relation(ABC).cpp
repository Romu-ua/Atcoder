#include <iostream>
#include <vector>
using namespace std;

//辺に重みがある場合なので
struct Edge {
    int to; //行き先
    int weight; //重み
    Edge(int t, int w) : to(t), weight(w) { } //構造体の初期化、toをtでweightをwで初期化している。
};


vector<int> color;
void dfs(vector<vector<Edge>> &G, int v, int cur = 0){
    //最初は0で決めておく。
    color[v] = cur;
    for(auto next_Edge : G[v]){ //ここの処理に注意。
        if(color[next_Edge.to] != -1) continue;
        if(next_Edge.weight % 2 == 0) {
            dfs(G, next_Edge.to, cur);
        } else {
            dfs(G, next_Edge.to, 1 - cur);
        }
    }
}


int main() {
    int N;
    cin >> N;
    vector<vector<Edge>> G(N);
    vector<int> w(N);

    for(int i = 0; i < N-1; i++){
        int u, v , w;
        cin >> u >> v >> w;
        G[u-1].push_back(Edge(v-1,w));
        G[v-1].push_back(Edge(u-1,w));
    }

    color.assign(N, -1);

    for(int v = 0; v < N; v++){
        if(color[v] != -1) continue;
        dfs(G, v);
    }

    for(int i = 0; i < N; i++){
        cout << color[i] << endl;
    }
}