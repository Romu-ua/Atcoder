#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false;}

int main() {
    int D, N;
    cin >> D >> N;
    vector<int> Day(D);
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < D; i++) {
        cin >> Day[i];
    }
    for (int i = 0; i < N; i++) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        a[i] = ai, b[i] = bi, c[i] = ci; 
    }

    // その日に着ることができるかどうか、きれないものは参照しなくて良い。
    vector<vector<bool>> suit(D, vector<bool>(N, false));
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            suit[i][j] = (a[j] <= Day[i] && Day[i] <= b[j]);
        }
    }

    // 初期化    
    vector<vector<int>> dp(D, vector<int>(N, -1));
    for (int j = 0; j < N; j++) {
        if(suit[0][j]) {
            dp[0][j] = 0;
        }
    }

    for (int i = 0; i < D-1; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] >= 0) {
                for (int k = 0; k < N; k++) {
                    if (suit[i+1][k]) {
                        //配るDPで書いている
                        chmax(dp[i+1][k], dp[i][j] + abs(c[j] - c[k]));
                    }
                }
            }
        }
    }

    int ans = -1;
    for (int j = 0; j < N; j++) {
        if (ans < dp[D-1][j]) {
            ans = dp[D-1][j];
        }
    }
    cout << ans << endl;
    return 0;
}