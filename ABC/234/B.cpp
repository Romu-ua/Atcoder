#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double ans = 0.0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            double dx = 0, dy = 0, d = 0;
            dx = abs(x[i] - x[j]), dy = abs(y[i] - y[j]);
            d = sqrt(dx*dx + dy*dy);
            ans = max(ans, d);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}