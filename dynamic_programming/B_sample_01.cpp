#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if( a < b ) { a = b; return true; } return false; }

const long long INF = 1LL << 60;
vector<long long> dp;

int main() {
    int N;
    cin >> N;

    //初期化
    dp.assign(N+1, INF);
    dp[0] = 0;

    //貰うDP
    for(int n = 1; n <= N; ++n) {
        for (int pow6 = 1; pow6 <= n; pow6 *= 6) {
            dp[n] = min(dp[n], dp[n - pow6] + 1);
        }

        for (int pow9 = 1; pow9 <= n; pow9 *= 9) {
            dp[n] = min(dp[n], dp[n - pow9] + 1);
        }
    }

    cout << dp[N] << endl;

    return 0;
}