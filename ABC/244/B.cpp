#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    
    int cnt = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            if (cnt == 0) {
                x++;
            } else if (cnt == 1) {
                y--;
            } else if (cnt == 2) {
                x--;
            } else {
                y++;
            }
        } else {
            cnt++;
            if (cnt == 4) cnt = 0;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}