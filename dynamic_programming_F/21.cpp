#include <bits/stdc++.h>
using namespace std;

// 模範解答はメモ化再帰で解いているのでまずそちらを実装してから添字に気をつけて配るDPで書いてみる
// メモ化再帰の時はDPテーブルをグローバルに書く、参照で渡してもいいけどめんどくさい。
vector<vector<vector<double>>> dp;
int n;

double rec(int i, int j, int k) {
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if (i > 0) res += rec(i-1, j, k) * i;
    if (j > 0) res += rec(i+1, j-1, k) * j;
    if (k > 0) res += rec(i, j+1, k-1) * k;
    res += n; // ここでNを使う必要があるのでnもグローバルで書いておく。
    res *= 1.0 / (i + j + k);

    return dp[i][j][k] = res;
}


int main() {
    cin >> n;
    // 残寿司個数が１２３の皿がいくつあるのかをとる。
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) one++;
        else if (a == 2) two++;
        else three++;
    }

    // 初期化 配列の長さを考えるのが面倒臭いがしっかり考えないとだめ。模範は取りうる最大の値300+1より310で書いている。
    dp.assign(301, vector<vector<double>>(301, vector<double>(301, -1)));
    double res = rec(one, two, three);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}