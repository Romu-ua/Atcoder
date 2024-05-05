#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

/*
いい添え字列はあんまりない、から、
例えば、４５６７８の数字を取ってくるとき、元の数列からその値の添え字列を取ってくる。
一旦２乗の計算量は出来る。
ー＞１から１０までの数字でｋ個の連続する数を取る　n-k+1通り。
ー＞答えを探すのはｋのオーダーで計算できる。から(n-k+1)kの計算量でこれがｎの２乗の計算量
ー＞ギリギリ間に合わない。

どの区間を選ぶ必要はある。
右端と左端の計算量を減らす。

・添え字の値の追加/削除
・右端と左端は最大値と最小値なのでsetを使う。
　ordered setを使う。
他の方法・スライド最小値、実はこれを解く問題。
添え字の列が並んでいるとして、ある区間の最小値を求めたいとき。
*/


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--; //こうすることで、qが０から始まることなってうれしい。
    //あらかじめ添え字列を作成しておく。
    vector<int> q(n);
    rep(i, n) q[p[i]] = i;

    int ans = n;
    set<int> st;
    rep(i, n) {
        st.insert(q[i]);
        if(st.size() > k) st.erase(q[i-k]); //一個追加して、一個削除する。
        if(st.size() == k){
            int now = *st.rbegin() - *st.begin(); //今考えているsetの中で差を求める。
            ans = min(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}