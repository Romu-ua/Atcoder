//貰うDP
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if(a < b) {
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;

//入力
int N;
long long h[100010];

//DPテーブル
long long dp[100010];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];

    //初期化
    for(int i = 0; i < 100010; i++) dp[i] = INF;

    //初期条件
    dp[0] = 0;

    //ループ
    for(int i = 1; i < N; i++) {
        chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if(i >= 2) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i-2]));
    }
    
    cout << dp[N-1] << endl;
}