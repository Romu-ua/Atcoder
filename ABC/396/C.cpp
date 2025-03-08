#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> b(n), w(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0LL));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            if (j >= i) {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + b[j] + w[i]);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << (j == n ? '\n' : ' ');
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
