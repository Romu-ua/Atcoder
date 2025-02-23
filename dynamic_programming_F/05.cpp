#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}

// DPテーブルを表示する関数
void printDP(const vector<vector<long long>>& dp, int N, int maxV) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= maxV; j++) {
            if (dp[i][j] == (1LL << 60)) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}


int main() {
    long long N, W;
    cin >> N >> W;
    vector<long long> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    
    const long long INF = 1LL << 60;
    // valueを横軸に取ってdpテーブルを作成すると、さっきみたいに横の長さが決まるわけじゃないから
    // 適当に決めとく。一応決め方として条件を見て上限を見定めることはできるけどめんどくさいから大体超えないだろうって値でいい。
    vector<vector<long long>> dp(N+1, vector<long long>(100010, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10010; j++) {
            chmin(dp[i+1][j], dp[i][j]);
            // if(dp[i+1][j+v[i]] <= W) chmin(dp[i+1][j+v[i]], dp[i][j] + w[i]); //これはデフォルトの値がINFなので実行されないのか.
            if(j+v[i] < 100010) chmin(dp[i+1][j+v[i]], dp[i][j] + w[i]);
        }

        printDP(dp, N, 10); // 価値は最大100まで表示
    }

    int result = 0;
    for (int i = 0; i < 100010; i++) {
        if(dp[N][i] <= W) chmax(result, i);
    }
    cout << result << endl;
    return 0;
}