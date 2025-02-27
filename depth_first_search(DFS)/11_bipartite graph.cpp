#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
bool dfs(Graph &G, int v, int cur = 0){
    //0は白確、1は黒確、-１は未探索
    color[v] = cur;
    for(auto next_v : G[v]){
        if(color[next_v] != -1) {
            if(color[next_v] == cur) return false;
            continue;
        }

        if(!dfs(G, next_v, 1 - cur)) return false;
    }
    return true;
}


int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b; // aとbがつながっている時、この実装になり説明上はわかりやすいがこのまま使うことができる問題は少ないな。
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N, -1);
    bool is_bipartite = true;
    for(int v = 0; v < N; v++){
        if(color[v] != -1) continue;
        if(!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}