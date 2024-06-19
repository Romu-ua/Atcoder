#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true;} return false; }

// 全ての通りを試すと2^N通りあるから、動的計画法を行う。
// dpの要素は重要度
// ナップサック問題の典型。重量が幅で、価値が重要度に当たる。
// テンプレのナップサック問題に貼れる写真の枚数の制限がかかる。
// Wが計算ソフトの幅、Nがスクリーンショットの枚数、Kが貼れる枚数。

int main() {
    int W, N, K;
    cin >> W >> N >> K;
    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    // vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(K+1, vector<int>(W+1, 0)));


    // 外側のループが使う写真を選んでいる。内側のループは幅がWになるまで重要度を計算している。
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            for (int sum_w = 0; sum_w <= W; sum_w++) {
                //単に上から下ろしたもの
                dp[i+1][k][sum_w] = dp[i][k][sum_w];
            }
        }
        for (int k = 0; k < K; k++) {
            for(int sum_w = 0; sum_w < W; sum_w++) {
                int w = sum_w + a[i];
                if(w > W) break;
                chmax(dp[i+1][k+1][w], dp[i][k][w] + b[i]);
            }
        }
    }

    int best = 0;
    for (int k = 0; k <= K; k++) {
        for (int sum_w = 0; sum_w <= W; sum_w++) {
            chmax(best, dp[N][k][sum_w]);
        }
    }

    cout << best << endl;

    return 0;
}