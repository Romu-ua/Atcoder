#include <bits/stdc++.h>
using namespace std;

// 樹形図をこのようなDPに落とし込めるのはすごいな。

int main() {
    int N;
    cin >> N;
    vector<double> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(N+1, vector<double>(N+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i+1; j++) {
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1 - p[i]);
        }
    }

    double result = 0;
    for (int j = N/2 + 1; j < N+1; j++) {
        result += dp[N][j];
    }

    cout << fixed << setprecision(10) <<result << endl;
    return 0;
}