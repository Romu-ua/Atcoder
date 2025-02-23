#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    int cnt = 1;
    while (true) {
        for (int i = 0; i < n; i++) {
            a[i] /= 2;
            if (a[i] % 2 == 1) {
                cout << cnt << endl;
                return 0;
            }
        }
        cnt++;
    }
    return 0;
}