#include <bits/stdc++.h>
using namespace std;

int main() {
    // 尺取法です。確実に。
    // 純粋な尺取法は正の数の時のみに簡単に実装できるが、マイナスの値が入っている時は現状する可能性があるから単純な実装ではできない
    // 累乗和を求めてから尺取ほうを実装する
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 初期化 確か半開区間でやるから右はn-1まで
    int l = 0, r = 0;
    long long ans = 0;
    int result = 0;
    while(r < n) {
        ans += a[r];
        r++;
        while(ans > k && l < r) {
            ans -= a[l];
            l++;
        }

        if (ans == k) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}