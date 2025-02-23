#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(N+1, vector<long long>(100010, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 100010; j++) {
            chmin(dp[i+1][j], dp[i][j]);
            if(j+v[i] < 100010) chmin(dp[i+1][j+v[i]], dp[i][j]+w[i]);
        }
    }

    long long ans = 0; 
    for (int i = 0; i < 100010; i++) {
        if(dp[N][i] <= W) ans = i;
    }

    cout << ans << endl;

    return 0;
}