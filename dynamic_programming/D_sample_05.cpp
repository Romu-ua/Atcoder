#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 10000;

int main() {
    int N, K;
    cin >> N >> K;

    // F[i] := 決まっている日がindex、パスタの種類が要素の配列
    vector<int> F(N, -1);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        F[a-1] = b-1;
    }

    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(3, vector<long long>(3, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                // パスタの候補 デフォルトは全てから選択できる。
                // F[i] >= 0　つまり決まっている時、候補はF[i]だけになる。
                vector<int> cs = {0, 1, 2};
                if(F[i] >= 0) cs = {F[i]};
                for (int c : cs) {
                    // 三日連続なら抜ける
                    if(i >= 2 && a == b && b == c) continue;
                    dp[i+1][b][c] += dp[i][a][b];
                    dp[i+1][b][c] %= MOD;
                }
            }
        }
    }

    int result = 0;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            result += dp[N][a][b];
            result %= MOD;
        }
        
    }

    cout << result << endl;
    return 0;
}