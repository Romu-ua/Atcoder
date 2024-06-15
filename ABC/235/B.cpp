#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long long ans = h[0]; // これのせいで10分掛かってもうたー
    for (int i = 1; i < n; i++) {
        if (h[i-1] < h[i]) {
            ans = h[i];
        } else {
            cout << ans << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}