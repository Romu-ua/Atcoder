#include <bits/stdc++.h>
using namespace std;

/*
グラフの同型性の確認

N <= 8なので全探索ができる。
形だけ判定したいとき、グラフの頂点の番号の振り方は自由。
なので、番号を振り直すことを全探索することで一致しているのかを確かめる。
これが何通りあるのかというと N! これが書ければ合格。
next_permutationを使う。
*/


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ga(n);
    vector<vector<int>> gb(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ga[a].emplace_back(b);
        ga[b].emplace_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gb[a].emplace_back(b);
        gb[b].emplace_back(a);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;

    do {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j : ga[i]) {
                g[a[i]].emplace_back(a[j]);
            }
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << "No" << endl;
    return 0;
}