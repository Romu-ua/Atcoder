#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int ans = 0;
    while(true) {
        if (x >= y) break;
        if (x < y) {
            x += 10;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}