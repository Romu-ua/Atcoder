#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1, true);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[ai] = false;
    }

    vector<long long> dp(n+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= min(n, i+2); j++) {
            if (a[j]) {
                dp[j] += dp[i];
                dp[j] %= 1000000007;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}