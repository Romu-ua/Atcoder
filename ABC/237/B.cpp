#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}