#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> seen, finished; //seenは行きがけの意味で、finishedは帰りがけの意味で、訪問済みか

//サイクル復元のための情報
int pos = -1;
stack<int> hist; //訪問履歴

void dfs(Graph &G, int v, int p){
    seen[v] = true;
    hist.push(v);
    for(auto nv : G[v]){
        //逆流はなし
        if (nv == p) continue;

        //完全に終了した頂点はスルー
        if(finished[nv]) continue;

        //サイクル検出
        if(seen[nv] && !finished[nv]){
            pos = nv;
            return;
        }

        //再帰的に探索
        dfs(G, nv, v);

        //サイクルを検出したなら抜ける
        if(pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}


int main() {
    int N;
    cin >> N;

    Graph G(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //探索
    seen.assign(N, false), finished.assign(N, false);
    pos = -1;
    dfs(G, 0, -1);

    set<int> cycle;
    while(!hist.empty()){
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if(t == pos) break;
    }

    int Q;
    cin >> Q;
    for(int _ = 0; _ < Q; _++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        if(cycle.count(a) && cycle.count(b)) cout << 2 << endl;
        else cout << 1 << endl;
    }
}
