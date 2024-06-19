#include <bits/stdc++.h>
using namespace std;
//おそらく解く、解かないや選ぶ、選ばない、のように全探索するとn^2やn^3のときにDPって使えそう。
//えらぶ選ばないだけだと、bit全探索も考えられるけど。

int main() {
    int N;
    cin >> N;
    vector<long long> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];

    // 今回は「 i 個の整数の中からいくつか選んで j を作れるか」をdpの要素する。
    // dp[i][j] = true のとき
    // dp[i+1][j] = true;
    // dp[i+1][j+a[i]] = true;
    // 配るDPの考えかをするとこのようになる。と思う。

    // 競プロ強い人がグローバルに配列を要素数を決め打ちで定義しているのは、
    // このように配列の要素数を決めるのがめんどくさいからって理由も結構大きい気がする。+1は必要。i番目がi+1番目を考えていることと同値であるから。
    vector<vector<int>> dp(N+1, vector<int>(10001, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j <= 10000; j++) {
            if(!dp[i][j]) continue;
            dp[i+1][j] = true; // これはどの場合でも成り立つ。
            if(j+p[i] <= 10000) dp[i+1][j+p[i]] = true;
        }
    }

    int res = 0;
    for(int j = 0; j <= 10000; j++) {
        if (dp[N][j]) res++;
    }

    cout << res << endl;

    return 0;
}