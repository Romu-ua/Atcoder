#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x; 
    cin >> n;
    long long t[n];
    int k[n];
    vector<vector<int>> e(n);

    bool used[n];

    for(int i = 0; i < n; i++) {
        used[i] = false;
    }

    for(int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            cin >> x;
            //0のノードはk = 0なので、0から出ている辺はない。
            //問題文より、大きい方から小さい方へ伸びる辺は存在していない。
            e[i].emplace_back(x-1);
        }
    }

    //一番最後のノードをtrueにして初期化。
    //ノードの番号は0-indexとして考えている。
    long long ans = 0;
    used[n-1] = true;
    for(int i = n-1; i >= 0; i--) {
        if(used[i]) {
            ans += t[i];
            for(int j = 0; j < k[i]; j++) {
                used[e[i][j]] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}