#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false; }

const long long INF = 1LL << 60;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n+1, INF);
    dp[0] = 0;


    for (int i = 0; i <= n; i++) {
        for (int pow6 = 1; i+pow6 <= n; pow6 *= 6) {
            chmin(dp[i+pow6], dp[i]+1);
        }
        for (int pow9 = 1; i+pow9 <= n; pow9 *= 9) {
            chmin(dp[i+pow9], dp[i]+1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}