//ABC040 https://atcoder.jp/contests/abc040/tasks/abc040_c
#include <bits/stdc++.h>
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
        a = b;
        return true;
    }
    return false;
}


const long long INF = 1LL << 60;
//入力
int N;
vector<long long> h;

//DPテーブル
vector<long long> dp;

int main() {
    int N;
    cin >> N;
    h.resize(N);
    for(int i = 0; i < N; i++) cin >> h[i];
    dp.resize(N);
    for(int i = 0; i < N; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i = 1; i < N; i++) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i-1]));
        if(i >= 2) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N-1] << endl;
}