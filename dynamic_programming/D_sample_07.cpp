#include <bits/stdc++.h>
using namespace std;

/*
「何かを固定してみると突破口が開けるかもしれない」byけんちょん


*/

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<long long>> P(10);
    for (int i = 0; i < N; ++i) {
        long long price, type;
        cin >> price >> type;
        --type;
        P[type].push_back(price);
    }

    //前処理
    for (int i = 0; i < 10; i++) {
        sort(P[i].begin(), P[i].end(), greater<long long>());
    }
    vector<vector<long long>> val(10);
    for (int i = 0; i < 10; i++) {
        //売らないときは0円なのでこの分を入れてP[i].size()+1
        val[i].assign(P[i].size()+1, 0);
        for (int j = 0; j < P[i].size(); j++) {
            val[i][j+1] = val[i][j] + P[i][j];
        }
        for (int j = 0; j < P[i].size(); j++) {
            // j-1円増える本がj冊あるからj*(j-1)になる。からこれで良い。
            val[i][j] += j * (j-1);
        }
    }

    // DP
    vector<vector<long long>> dp(11, vector<long long>(K+1, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < val[i].size() && j+k <= K; k++) {
                // jはジャンルiまで見て行った時の最大の売値
                // kは残りの冊数まで売った時の最大の売値
                dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + val[i][k]);
            }
        }
    }

    cout << dp[10][K] << endl;
    return 0;
}