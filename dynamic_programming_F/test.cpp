#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// DP テーブル
long long dp[3100][3100];

void printDPTable(int N) {
    cout << "DP Table:" << endl;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (j < i) cout << setw(4) << " ";
            else cout << setw(4) << dp[i][j];
        }
        cout << endl;
    }
    cout << "----------------------" << endl;
}

int main() {
    // 入力受け取り
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 初期条件
    for (int i = 0; i < N; ++i) dp[i][i] = 0;
    
    printDPTable(N); // 初期状態を表示

    // DP
    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i + len <= N; ++i) {
            int j = i + len;

            // 先手番
            if ((N - len) % 2 == 0)
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);

            // 後手番
            else
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
        }
        printDPTable(N); // 各長さごとにテーブルを表示
    }

    // 答え
    cout << dp[0][N] << endl;
}
