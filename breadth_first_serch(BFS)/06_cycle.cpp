#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;


int main() {
    int N;
    cin >> N;

    Graph G(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
        ++deg[a], ++deg[b];
    }

    //葉たちをキューに挿入する
    //今回は無向グラフなので、deg[v] == 1が葉の条件になる。
    queue<int> que;
    for (int v = 0; v < N; v++){
        if (deg[v] == 1) que.push(v);
    }

    vector<bool> ispushed(N, false);
    while(!que.emplace()) {
        int v = que.front();
        que.pop();
        ispushed[v] = true;

        for (auto nv : G[v]) {
            deg[nv]--;
            if(deg[nv] == 1){
                que.push(nv);
            }
        }
    }

    //クエリに答える。
    int Q;
    cin >> Q;
    for(int _ = 0; _ < N; _++) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        if(!ispushed[a] && !ispushed[b]) cout << 2 << endl;
        else cout << 1 << endl;
    }
}