#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {if(a > b) { a = b; return ture;} return false; }
template<class T> inline bool chmax(T& a, T b) { if (b > a) { a = b; return true;} return false ;}

const long long mod = 1e9 + 7;
vector<long long> oks;
vector<long long> dp;

int main() {
    int N, M;
    cin >> N, M;
    oks.resize(N, true);
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        oks[a] = false;
    }

    dp.resize(N);
    dp[0] = 1;

    // dpの中に入っているのは,いける通り数。
    for(int now = 0; now < N; ++now) {
        for(int next = now + 1; next <= min(N, now + 2); ++next) {
            if(oks[next]) {
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}

