#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<vector<int>> vec(n, vector<int>(n, 0)); //n行正則行列を0で初期化した。
//     int k = 0, l = 0; 
//     rep(i, n) {
//         cin >> k >> l;
//         vec[k-1][l-1] = 1;
//         vec[l-1][k-1] = 1;
//     }
//     //入力の確認
//     // rep(i, n) {
//     //     rep(j, n){
//     //         cout << vec[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     //取りうる場合を列挙し、その時、遷移行列に適合しているのかを確かめる。
//     vector<int> init_vec(n);
//     rep(i, n) {
//         init_vec[i] = i; //next_permutationに入れるために昇順にする。
//     }
//     vector<vector<int>> a;
//     do {
//         if(init_vec.front() != 0) break; //最初は１じゃないね。間違えてた。
//         a.emplace_back(init_vec);
//         //内容の確認
//         // rep(i, n){
//         //     cout << init_vec[i] << " ";
//         // }
//         // cout << endl;
//     } while(next_permutation(init_vec.begin(), init_vec.end()));



//     //この順列を書き出す処理は簡単な問題だとよく出てくるのかもね。覚えておきたい。
//     int cnt = 0;
//     rep(i, a.size()){
//         bool flag = true;
//         rep(j, n-1) {
//             if(vec[a[i][j]][a[i][j+1]] != 1) {
//                 flag = false;
//             }
//         }
//         if(flag) cnt++;
//     }
//     cout << cnt << endl;
//     return 0;
// }
// //この実装は連結だけしか見ていないから無理だ。

const int nmax = 8;
bool graph[nmax][nmax]; //graphは隣接行列を表している。

int dfs(int v, int N, bool visited[nmax]) {
    bool all_visited = true;

    //訪れたのかを全てチェックして、どっかfalseがあったらfalseになる。
    for(int i = 0; i < N; ++i) {
        if(visited[i] == false) {
            all_visited = false;
        }
    }

    if(all_visited) {
        return 1;
    }

    int ret = 0; //最終的に出力している値なので、何通りあるのかを表す。

    for(int i = 0;i < N; ++i) {
        if(graph[v][i] == false) continue; //今いるノードからどこに行けるのかを確認。
        if(visited[i]) continue;  //訪れていたら移れない。

        visited[i] = true;
        ret += dfs(i, N, visited); //今いるノードを行ける次に進めて、もう一度最初から深さ優先探索をやる。
        visited[i] = false;
    }
    return ret;
}



int main() {
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A-1][B-1]=graph[B-1][A-1] = true;
    }
    //隣接行列を考えて受け取るまでは出来てる。

    bool visited[nmax];
    for(int i = 0;i < N; ++i) {
        visited[i] = false;
    }

    visited[0] = true;
    //この発想は参考になる。
    //訪れたか、の配列を作成して、スタートである、1 のノードはtrueにしておいて、
    //v:今いるノード、N:ノードの個数、visited:訪れたのかのフラグ、

    cout << dfs(0, N, visited) << endl;
    return 0;
}