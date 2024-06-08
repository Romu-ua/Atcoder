#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long cnt = 0;
    for(int i = 1; i <=cbrt(n); i++) {
        for(int j = i; j <= sqrt(n); j++) {
            // double num = double(n)/(i*j);
            cout << "i : " << i << " j : " << j << endl;
            int num = n/(i*j);
            cout << num << endl;
            //numがjより小さい数の回数の合計をとる。
            cnt += j - 1;
            ans += num;
        }
    }

    cout << ans - cnt << endl;
    return 0;
}