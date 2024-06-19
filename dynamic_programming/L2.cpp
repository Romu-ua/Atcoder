#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 今回はdpの縦横はnを超えることはないからnにしておく。
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // この実装は漸化式と遷移をイメージした方が実装しやすい。表をイメージしての実装は個人的にやりずらい。

    // lenは残りの石の個数。iは左側閉区間、jは右側開区間。
    // dpの要素は残っている石が[i, j) の時の X - Y の値。
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i+len <=n; i++) {
            int j = i + len;

            if ((n-len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            } else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][n] << endl;

    return 0;
}