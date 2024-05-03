/*メモ


*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i) //マクロ


int main() {
    int n, q;
    cin >> n >> q;
    vector<bool> hole(n+1); //１からnって言われているからn+1まで書くことでnを表現できる
    for (int i = 1; i <= n; ++i) {
        hole[i] = true; //最初は全て歯が生えているのでtrueで初期化
    }
    rep(qi, q) { //一瞬qiなくね？？って思ったけど、iは()内で定義するやつだった。
        int t;
        cin >> t;
        hole[t] = !hole[t]; //!で０１を反転させる。
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(hole[i] == true) ans++;
    }
    cout << ans << endl;

    return 0;
}