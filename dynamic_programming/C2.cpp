#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return true; }


int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> d[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j< 3; j++) {
            for (int k = 0; k < 3; k++) {
                if(j != k) chmax(dp[i+1][k], dp[i][j] + d[i][k]);
            }
        }
    }

    int ans = 0; 
    for (int i = 0; i < 3; i++) {
        chmax(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}