#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int b_a[n];

    rep(i, n){
        cin >> a[i] >> b[i];
        b_a[i] = b[i] - a[i]; //頭の大きさ
    }

    // 最大要素を取得する
    auto max_it = max_element(b_a, b_a+n);
    int max_index = distance(b_a, max_it);
    long long max_value = *max_it;
    
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
    }

    cout << sum_a+max_value << endl;

    return 0;
}