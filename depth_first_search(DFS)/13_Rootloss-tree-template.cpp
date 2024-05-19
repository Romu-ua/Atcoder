#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//v:現在捜索中の頂点   p:vの親(rootの時は-1) 
void dfs(Graph &G, int v, int p){
    for(auto nv : G[v]){
        if(nv == p) continue;
        dfs(G, nv, v);
    }
}

int main() {
    int N;
    cin >> N;

    Graph G(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }    

    int root = 0; //決め打ちで頂点0をrootとする。
    dfs(G, root, -1);
}