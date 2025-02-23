#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string a, b;
    cin >> k >> a >> b;

    long long a10 = 0;
    for(int i = 0; i < a.length(); i++) {
        long long value = a[i] - '0';
        a10 = a10*k + value;
    }

    long long b10 = 0;
    for(int i = 0; i < b.length(); i++) {
        long long  value = b[i] - '0';
        b10 = b10*k + value;
    }
    
    long long ans = a10 * b10;

    cout << ans << endl;
    return 0;
}

//1:05:13