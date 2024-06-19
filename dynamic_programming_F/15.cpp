#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }


int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(W+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j+w[i] <= W) chmax(dp[i+1][j+w[i]], dp[i][j]+v[i]);
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}