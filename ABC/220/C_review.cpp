#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long x;
    cin >> x;
    long long s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }
    long long p = x/s;
    long long ans = p*n;
    long long now = p*s;

    for(int i = 0; i < n; i++) {
        now += a[i];
        ans++;
        if(now > x) break;
    }
    cout << ans << endl;
    return 0;
}