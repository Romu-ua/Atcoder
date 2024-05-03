#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i) //これは今後も使っていく。
using namespace std;

int main() {
    //階乗のコードがわからんかった。

    //今回はN<=8なので、全て列挙してもできる。8! ~= 40000 next_permutaion→配列を与えると、順列を列挙できる。
    //しかし、上は必要ない。
    //２点間の辺を考えて、この辺が何回使われるのかを求めて足し合わせることでもとまる。
    //全ての辺の使われる回数は全て同じになる。階乗の計算なので明らか。つまり何回使うか　X を求める。

    int n;
    cin >> n;
    vector<int> x(n), y(n); //ここも無理に2次元配列を使う必要がないことを意味している。
    
    rep(i, n) cin >> x[i] >> y[i];
    //lambda式を使う
    auto dist = [&](int i, int j) {
        double dx = x[i] - x[j];
        double dy = y[i] - y[j];
        return sqrt(dx*dx + dy*dy);
    };

    vector<int> p(n);
    rep(i, n) p[i] = i; //0からn-1までの値を順に入れた。これを使って順列を列挙する。
    double len = 0;
    int cnt = 0;

    do {
        rep(i, n-1) {
            len += dist(p[i], p[i+1]);
        } 
        cnt++;
    } while (next_permutation(p.begin(), p.end())); //next_permutationは配列の先頭と最後を渡すことで、次の順列を返す関数。do-whileと相性が良い。
    double ans = len/cnt;                           //next_permutationは昇順にソートされた配列を入力とする。
    printf("%.10f\n", ans);                         //配列そのものを変更する。
    return 0;
}