#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// 入力を受け取る配列
vector<vector<long long>> a;
vector<vector<long long>> dp;

int main() {
    int N;
    cin >> N;

    a.resize(N, vector<long long>(3));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    // 多分これがあるから配列を定義するときにa[10010][3] dp[100010][3]をグローバルで定義しているのだと思う。
    // 今回は0-indexでi日目はi+1日目として表される。
    dp.resize(N+1, vector<long long>(3, 0));
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j == k) continue;
                chmax(dp[i+1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    //答え
    long long res = 0;
    for(int j = 0; j < 3; ++j) {
        chmax(res, dp[N][j]);
    }
    cout << res << endl;
    return 0;
}