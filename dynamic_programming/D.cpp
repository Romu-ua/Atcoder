#include <iostream>
#include <vector>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false; }

//使う配列,変数の定義
vector<long long> weight, value;
vector<vector<long long>> dp;


int main() {
    int N;
    long long W;
    cin >> N >> W;
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

    //今回は「以下」なので初期は0でいい。
    //配列の初期化がめんどい、ってか間違えやすいと思うからdp[110][100010]のように定義しているのか。
    dp.assign(N, vector<long long>(W+1, 0));
    //DPループ
    //DPに入っているのは、valueの合計。i は品物の番号。
    for (int i = 0; i < N; ++i) {
        for(int sum_w = 0; sum_w <= W; ++sum_w) {

            //i ば番目の品物を選ぶとき
            if (sum_w - weight[i] >= 0) {
                chmax(dp[i+1][sum_w], dp[i][sum_w - weight[i]] + value[i]);
                //上からの矢印と、斜めからの矢印で比較している。
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}