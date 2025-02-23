#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    // for(ll a = 1; a*a*a <= n; a++) {
    //     for(ll b = a; a*b*b <= n; b++) {
    //         ll maxC = n/(a*b);
    //         ans += maxC - b + 1;
    //     }
    // }

    for(ll a = 1; a <= cbrt(n); a++) {
        for(ll b = a; b <= sqrt(n/a); b++) {
            ll maxC = n/(a*b);
            ans += maxC - b + 1;
        }
    }

    cout << ans << endl;
    return 0;
}