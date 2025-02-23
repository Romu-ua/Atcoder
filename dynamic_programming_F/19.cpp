#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j+1 < w && field[i][j+1] != '#') {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= 1000000007;
            }
            if (i+1 < h && field[i+1][j] != '#') {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= 1000000007;
            }
        }
    }

    cout << dp[h-1][w-1] << endl;
    return 0;
}