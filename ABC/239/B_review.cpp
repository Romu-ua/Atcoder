#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    if (x < 0 && x % 10 != 0) {
        cout << x/10 - 1 << endl;
        return 0;
    }
    cout << x/10 << endl;

    return 0;
}