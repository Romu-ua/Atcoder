#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false; }

// DPの更新順序が自明なら本来は何でも実装できるが、
// 今回はややこしいのでメモ化再帰で更新順序を有耶無耶にして実装する。

int N;
vector<vector<vector<double>>> dp;

double rec(int i, int j, int k) {
    if (dp[i][j][k] >= 0) return dp[i][j][k]; // 更新済みならパス
    if (i == 0 && j == 0 && k == 0) return 0.0;

    double res = 0.0;
    if (i > 0) res += rec(i-1, j, k) * i;
    if (j > 0) res += rec(i+1, j-1, k) * j;
    if (k > 0) res += rec(i, j+1, k-1) * k;
    res += N;
    res *= 1.0 / (i + j + k);
    return dp[i][j][k] = res;
}

int main() {
    cin >> N;
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            one++;
        } else if (a == 2) {
            two++;
        } else if (a == 3) {
            three++;
        }
    }

    // 初期化 メモ化再帰の時はDPをグローバルで宣言しているから初期化は慣れないな。
    // 今回は全ての次元でN個を超えることはないのでN＋1で実装している
    dp.resize(N+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));
    double result = rec(one, two, three);
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}