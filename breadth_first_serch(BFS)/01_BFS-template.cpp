#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //頂点数と辺数
    int N, M;
    cin >> N >> M;

    //グラフ入力受け取り(無向グラフを想定、遷移リスト形式を想定)
    Graph G(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //BFS　のためのデータ構造
    vector<int> dist(N, -1);
    queue<int> que; //その時点での「発見済みだが未訪問な頂点」を格納するキュー

    //初期条件(頂点0を初期ノードとする)
    dist[0] = 0;
    que.push(0);

    //BFS　開始(キューが空になるまで探索を行う)
    while(!que.empty()) {
        int v = que.front();
        que.pop(); //取り出した時点で探索済みで、今見ている頂点。

        //v から辿れる頂点を全て調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; //すでに発見済みの頂点の場合はスキップ

            //新たな白色頂点 nv について距離情報を更新してキューに追加する。
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    //結果出力(各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; v++){
        cout << v << ": " << dist[v] << endl;
    }

}