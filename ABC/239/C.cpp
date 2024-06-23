#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x2 = x2-x1, y2 = y2-y1;
    vector<pair<int, int>> vec = {{0, 0}, {0, 2}, {0, 4}, {2, 0}, {4, 0},
                                    {1, 1}, {2, 4}, {3, 1}, {3, 3}, {4, 3}};

    for (const auto& p : vec) {
        if (p.first == x2 && p.second == y2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}