#include <bits/stdc++.h>
using namespace std;

bool isprime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // 全探索でいけるわ。
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <=b; i++) {
        bool flag = true;
        for (int j = c; j <= d; j++) {
            if (isprime(i+j)) break;
            if (j == d && flag){
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }

    cout << "Aoki" << endl;
    return 0;
}