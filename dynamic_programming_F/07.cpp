#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

const long long INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<long long> dp(n, INF);
    dp[0] = 0;
    // 配るDPで書く。
    for (int i = 0; i < n; i++) {
        if(i < n-1) chmin(dp[i+1], dp[i]+abs(h[i] - h[i+1]));
        if(i < n-2) chmin(dp[i+2], dp[i]+abs(h[i] - h[i+2]));
    }

    cout << dp[n-1] << endl;
    return 0;
}