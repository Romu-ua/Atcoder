/*
結構変わった問題らしい
確かに制約を見ると。。。もっと条件見ないといけないな。

好きな組を選んでswapする。
いろんなやり方がある。
パッと思いつく方法でもn-1回で収まるらしい。


方向性は2つある。
１つ目:
前から数を選んでいき、それを正しい位置に持っていく。

3 1 2 5 4 ->2 1 ③ 5 4 -> ① ② ③ 5 4 -> ① ② ③ ④ ⑤ 
n-1回で収まるのか問題は、正しい位置に一箇所ずつ増えていく。
n-1個あっていれば最後の1個は合うのでn-1回でできる。

2つ目：
最小値を持ってこよう。前から合わせていこうっていう方針。
3 1 2 5 4 -> ① 3 2 5 4 -> ① ② ③ 4 5 -> ① ② ③ ④ ⑤
私の解法やな。
これを単純にやるとTLEになる。

for i = 1...N
    for j = 1...N
これはn**2/2ぐらいの計算量でnの２乗のオーダー

ではどうすれば良いのか？

「どこにあるのか？」を表す配列を作成する。
1:3
2:1
3:2
4:5
5:4

計算量を削減する代わりにメモリの使用量を犠牲にしようってこと。これは定数倍のオーダーで計算できる。
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i+1]; //aの添字を0スタートか1スタートか、どちらに合わせるのか悩ましいが、今回は、出力の方に合わせる。
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        while(a[i] != i) {
            int j = a[i];
            swap(a[i], a[j]);
            ans.emplace_back(i, j);
        }
    }
    cout << ans.size() << endl; //pairの数を見れば何回入れ替えたか見れるわ。

    for (auto [i, j] : ans) cout << i << " " << j << endl;//範囲ベースfor文の熟練度が足りてない。pairのやつをそれぞれに代入するにはこれは便利。
    
    //上記の範囲forと同じ意味を持つfor文
    // for (auto it = ans.begin(); it != ans.end(); ++it) {
    //     auto& pair = *it; //itはansのbeginを意味しているからこれでpairの参照が取得できる
    //     auto i = pair.first;
    //     auto j = pair.second;
    //     cout << i << " " << j << endl;s
    // }

    return 0;
}
