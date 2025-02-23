#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;


int main() {
    int n;
    cin >> n;
    // DPなん？
    // 桁に使える数字が１から９。確かにDPっぽい。
    vector<vector<mint>> dp(n+1, vector<mint>(10, 0));
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (j-1 >= 1) dp[i+1][j] += dp[i][j-1];
            dp[i+1][j] += dp[i][j];
            if (j+1 <= 9) dp[i+1][j] += dp[i][j+1];
        }
    }

    mint ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i];
    }

    cout << ans.val() << endl;
    return 0;
}