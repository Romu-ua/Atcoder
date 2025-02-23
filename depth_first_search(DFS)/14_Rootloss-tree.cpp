//根付き木の深さと部分木サイズ
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;
vector<int> subtree_size;
void dfs(Graph &G, int v, int p, int d){
    depth[v] = d;
    for(auto nv : G[v]) {
        if(nv == p) continue;
        dfs(G, nv, v, d+1);
    }

    //帰りがけに部分木サイズを更新する
    subtree_size[v] = 1; //自分自身のサイズ
    for(auto c : G[v]){
        if(c == p) continue;
        subtree_size[v] += subtree_size[c]; 
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

    int root = 0;
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root, -1, 0);

    for(int v = 0; v < N; v++){
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
    }
    
}