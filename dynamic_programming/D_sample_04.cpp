#include <bits/stdc++.h>
using namespace std;

//使う配列、変数の定義

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    // 表の縦はN＋1個で、横はN<=100までなので、全て9の時に全てプラスで900になるから、で0-indexなので901になる。
    // 要素は64bitを超えないって書いてあるからlong longを使う。
    vector<vector<long long>> dp(N+1, vector<long long>(21, 0));
    
    //初期化
    dp[1][a[0]] = 1;

    //DPループ
    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            if(dp[i][j] > 0) {
                int puls = j + a[i];
                int minus = j - a[i];

                if(puls >= 0 && puls <= 20) {
                    dp[i+1][puls] += dp[i][j];
                }
                if(minus >= 0 && minus <= 20) {
                    dp[i+1][minus] += dp[i][j];
                }
            }
        }
    }

    cout << dp[N-1][a[N-1]] << endl;
    return 0;
}