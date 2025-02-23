#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}


int main() {
    int N;
    cin >> N;
    vector<vector<long long>> a(N, vector<long long>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> dp(N+1, vector<long long>(3, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k != j) chmax(dp[i+1][k], dp[i][j] + a[i][j]);
            }
        }
    }

    long long result = 0;
    for (int j = 0; j < 3; j++) {
        chmax(result, dp[N][j]);
    }

    cout << result << endl;

    return 0;
}