#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    for(ll n = 1; n <= 1e13; n++) {
        ll ans1 = 0;
        for(ll a = 1; a*a*a <= n; a++) {
            for(ll b = a; a*b*b <= n; b++) {
                ll maxC = n/(a*b);
                ans1 += maxC - b + 1;
            }
        }

        ll ans2 = 0;
        for(ll a = 1; a <= cbrt(n); a++) {
            for(ll b = a; b <= sqrt(n/a); b++) {
                ll maxC = n/(a*b);
                ans2 += maxC - b + 1;
            }
        }

        if (ans1 != ans2) {
            cout << "Difference found at n = " << n << endl;
            cout << "Result of commented out loop: " << ans1 << endl;
            cout << "Result of executed loop: " << ans2 << endl;
            cout << "Difference: " << ans2 - ans1 << endl;
            break;
        }
    }

    return 0;
}
