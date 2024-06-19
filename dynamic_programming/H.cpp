#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if(a > b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T& a, T b) { if(a < b) { a = b; return true;} return false; }

// 高校の経路問題でグリットに通り数を書いていって求める問題と似ている。
// ってかそれを実装しているだけか。

// MOD
const int MOD = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD; // こーれ賢いな。確かにこれでいいのか。
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) cin >> a[i];

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(i+1 < H && a[i+1][j] == '.') add(dp[i+1][j], dp[i][j]);
            if(j+1 < W && a[i][j+1] == '.') add(dp[i][j+1], dp[i][j]);
        }
    }

    cout << dp[H-1][W-1] << endl;
    return 0;
}