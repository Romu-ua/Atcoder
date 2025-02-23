#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    // 初期化
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));

    // DP
    for (int len = 1; len <= N; len++) {
        for (int i = 0; i + len <= N; i++) {
            int j = i + len;

            // 先手版  後手番
            if ((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j]+ a[i], dp[i][j-1] + a[j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
    return 0;
}