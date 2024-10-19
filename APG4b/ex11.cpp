#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    for (int i = 1; i <= n; i++) {
        char op;
        int b;

        cin >> op >> b;

        if (op == '+') {
            a += b;
        } else if (op == '-') {
            a -= b;
        } else if (op == '*') {
            a *= b;
        } else {
            if (b == 0) {
                cout << "error" << endl;
                return 0;
            }
            a /= b;
        }

        cout << i << ":" << a << endl;
    }

    return 0;
}