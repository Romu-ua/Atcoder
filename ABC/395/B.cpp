#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n, '.'));

    for (int i = 1; i <= n; i++) {
        int j = n + 1 - i;
        if (i <= j) {
            char color = (i % 2 == 1) ? '#' : '.';

            for (int r = i - 1; r < j; r++) {
                for (int c = i - 1; c < j; c++) {
                    grid[r][c] = color;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
