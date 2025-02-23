#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    /*
    考察：
    一番上はBにすることができる。
    →n個のうち、最大のBを求める。これでもTLEする。
    ->b-aが最大値をaの合計を求めて
    */

   int n;
   cin >> n;
   vector<int> a(n), b(n);
   rep(i, n) cin >> a[i] >> b[i];
   int mx = 0;
   rep(i,n) mx = max(mx, b[i] - a[i]);
   ll ans = mx; //ここで、頭の高さの最大値をansに入れる。以下でAの合計値を足す。
   rep(i,n) ans += a[i];
   cout << ans << endl;
    return 0;
}