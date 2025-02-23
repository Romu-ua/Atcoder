#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false; }

int main() {
    string s, t;
    cin >> s >> t;

    // sとtの文字列の長さの制限は3000なので一つ増やして3001
    vector<vector<int>> dp(3001, vector<int>(3001, 0));
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }

    // cout << dp[s.size()][t.size()] << endl;

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
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