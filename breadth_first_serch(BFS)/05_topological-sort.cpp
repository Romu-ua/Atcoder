#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

int main () {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    vector<int> deg(N, 0); //各頂点の出次数
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[b].push_back(a); //走査する順番は線が伸びてない方から。
        deg[a]++;
    }

    //シンクたちをキューに挿入する
    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) que.push(i);
    }

    //探索開始
    vector<int> order;
    while (!que.empty()) {
        //キューから頂点を取り出す
        int v = que.front();
        que.pop();
        order.push_back(v);

        //v へと伸びている頂点たちを探索する
        for (auto nv : G[v]) {
            //辺を削除することは、頂点を削除する操作と同値
            deg[nv]--;
            //これによってシンクになった頂点をキューに追加
            if(deg[nv] == 0) {
                que.push(nv);
            }
        }
    }

    //答えをひっくり返す
    reverse(order.begin(), order.end());
    for (auto v : order) cout << v << endl;
}

