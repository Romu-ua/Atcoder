#include <bits/stdc++.h>
using namespace std;

/*
言われた通りに実装するとTLEする。
計算量Qはかかるので、一回の計算量を減らしていく。

番号とそれが現れたindexを持っておく
これをmapで持っておく。
そうすると、オーダー(N+Q)ぐらいの計算量がかかる
*/

int main() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a].push_back(i+1); // 存在しない時は0で初期化される。デフォルトコンストラクタが処理してくれているらしい。
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        vector<int>& p = mp[x]; // ここで参照にしないとコピーが起こる。
        if (p.size() < k) cout << -1 << endl;
        else cout << p[k-1] << endl;
    }
    return 0;
}