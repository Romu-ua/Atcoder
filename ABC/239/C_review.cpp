#include <bits/stdc++.h>
using namespace std;

int dist (int a, int b, int c, int d) {
    return (a - c)*(a - c) + (b - d)*(b - d);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int x = x1-2; x < x1+3; x++) {
        for (int y = y1-2; y < y1+3; y ++) {
            if (dist(x, y, x1, y1) == 5 && dist(x, y, x2, y2) == 5) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}