#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    int cx = 0, cy = 0, ct = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] - ct < abs(x[i] - cx + y[i] - cy)) {
            cout << "No" << endl;
            return 0;
        }
        if ((t[i] - ct) % 2 != abs(x[i] - cx + y[i] - cy) % 2) {
            cout << "No" << endl;
            return 0;
        }
        ct = t[i], cx = x[i], cy = y[i];
    }

    cout << "Yes" << endl;

    return 0;
}