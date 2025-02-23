#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> a;
vector<long long> product_result;
long long x;

void calculateProducts(long long row, long long currentProduct) {
    if (row == a.size()) {
        product_result.emplace_back(currentProduct);
        return;
    }

    for (long long num : a[row]) {
        // これがないとダメなのか。
        if (currentProduct > x / num) {
            continue;
        }
        calculateProducts(row+1, currentProduct*num);
    }
}

int main() {
    long long n;
    // long long x;
    cin >> n >> x;
    vector<long long> l(n);  
    a.resize(n);
    for (int i = 0; i < n; i++) {
        long long li;
        cin >> li;
        a[i].resize(li);
        l[i] = li;
        for (long long j = 0; j < li; j++) {
            cin >> a[i][j];
        }
    }

    // なるほど、Lの積が10^5なので全探索できるっぽい。
    // 実装どうするの？
    // for文はネストする回数が決まっていたらできるけど、今回は厳しそう。
    // 再帰関数で実装するのが良さそう。

    calculateProducts(0, 1);
    long long ans = 0;
    for (long long resultn : product_result) {
        if (resultn == x) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}