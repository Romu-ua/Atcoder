#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(200001, 0));
    dp[0][100000] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 200000; j++) {
            if (dp[i][j]) {
                dp[i+1][j+a[i]] = 1;
                dp[i+1][j+b[i]] = 1;
            }
        }
    }

    if(dp[n][100000+x]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}