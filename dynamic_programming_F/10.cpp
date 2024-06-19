#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false; }


int main() {
    int n;
    while(cin >> n) {
        if (n == 0) break;

        vector<long long> dp(n+1);
        dp[0] = 1;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= 3 ; j++) {
                if(i+j <= n)dp[i+j] += dp[i];
            }
        }
        cout << dp[n] / 3650 + 1 << endl;
    }
    return 0;
}