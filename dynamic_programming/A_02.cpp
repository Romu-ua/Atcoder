#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

//入力 
int N;
long long h[100010];

//DPテーブル
long long dp[100010];


int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }

    //初期化
    for(int i = 0; i < 100010; i++) {
        dp[i] = INF;
    }

    //初期条件
    dp[0] = 0;

    //ループ
    for(int i = 0; i < N-1; i++) {
        chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        chmax(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }

    cout << dp[N-1] << endl;

    return 0;
}