#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[30];

int main(void) {
    // 初期条件の設定
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    
    // DP テーブルの計算
    for (ll i = 3; i < 30; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    
    ll n;
    while (cin >> n, n) {
        printf("%d\n", ((dp[n - 1] + 9) / 10 + 364) / 365);
    }
    
    return 0;
}
