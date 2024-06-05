#include <bits/stdc++.h>
using namespace std;

/*
カレンダーの一般化した問題から、抜き出したものであるかどうかを判定する。

一つ目：
Bの左上のやつを見て、Aからサイズが同じ行列を持ってきてそれが一致しているのかをみる。
左上をどのように求めるか。
割ったもの商が行数、あまりが列のマス目になる。

二つ目：
下に行くと+7横に行くと+1という性質を使う。
これをチェックすれば良い。注意として最後のところのあまりは６になることを確認する。
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }

    int si = b[0][0] / 7;
    int sj = b[0][0] % 7;
    //最後の列が7以上だと枠からはみ出している。
    if(sj+m-1 >= 7) {
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //本来書かれているもの
            int nb = (si+i)*7 + (sj+j);
            if(b[i][j] != nb) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}