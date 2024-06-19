#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }

int main() {
    string s, t;
    cin >> s >> t;

    // DPテーブル この長さは決め打ち
    vector<vector<int>> dp(3001, vector<int>(3001, 0));

    // DPループ
    for (size_t i = 0; i < s.length(); i++) {
        for (size_t j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
            chmax(dp[i+1][j+1], dp[i][j+1]);
            chmax(dp[i+1][j+1], dp[i+1][j]);
        }
    }
    // 長さの結果は正しく取れている
    // cout << dp[s.length()][t.length()] << endl;

    // 復元
    string res = "";
    int i = s.length(), j = t.length();
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            --i;
        } else if (dp[i][j] == dp[i][j-1]) {
            --j;
        } else {
            res = s[i-1] + res;
            --i, --j;
        }
    }
    cout << res << endl;
    return 0;
}