#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false;}

// 配るDPと集めるDPのどちらを最初に考えるか。集めるDPの方がindexの範囲を考慮する必要性が低い気がするから
// 集める方を優先してコードを書こう。

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    } 

    const long long INF = 1LL << 60;
    vector<long long> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++){
        for (int k = 0; k <= K; k++) {
            if (i+k < N) chmin(dp[i+k], dp[i] + abs(h[i] - h[i+k]));
        }
    }

    cout << dp[N-1] << endl;
    return 0;
}