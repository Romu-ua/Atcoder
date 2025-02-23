#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<bool> dp(N+1);
    for (int i = 1; i < K+1; i++) {
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0 && !dp[i - a[i]]) {
                dp[i - a[i]] = true;
                break; // 一度でもtrue;になればもう見る必要がない。
            } 
        }
    }

    if (dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}