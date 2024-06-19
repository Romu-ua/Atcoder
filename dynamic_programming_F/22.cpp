#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(k+1, false);
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            // 実装のイメージとして、「遷移先にfalseがあればtrueになる」方を意識して実装すると、わかりやすいかも。
            if (i - a[j] >= 0) dp[i] |= !dp[i-a[j]]; // vectorで配列を作っているときはint型にしないと｜＝演算はできない。
        }
    }


    if (dp[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}