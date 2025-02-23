#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}

int main() {
    long long N, W;
    cin >> N >> W;
    vector<long long> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < W+1; j++) {
            chmax(dp[i+1][j], dp[i][j]);
            if (j+w[i] <= W) chmax(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}