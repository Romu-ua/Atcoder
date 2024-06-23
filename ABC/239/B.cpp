#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    string x_last = to_string(x);

    if (x < 0 && x_last.back() != '0') {
        cout << x/10 - 1 << endl;
        return 0;
    } else {
        cout <<  x/10 << endl;
        return 0;
    }
}