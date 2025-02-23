//行きがけ順と帰りがけ順を実装する
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> first_order; //行きがけ順
vector<int> last_order; //帰りがけ順

void dfs(Graph &G, int v, int &first_ptr, int &last_ptr){
    //行きがけ順をインクリメントしながらメモ
    first_order[v] = first_ptr++;

    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v, first_ptr, last_ptr);
    }

    //帰りがけ順をインクリメントしながらメモ
    last_order[v] = last_ptr++;
}


int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(a);
        G[b].push_back(b);
    }

    //頂点0をスタートとした探索
    seen.assign(N, false);
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    //各頂点 v の行きがけ順、帰りがけ順を出力
    for(int v = 0; v < N; v++){
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
    }
}