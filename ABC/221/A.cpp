#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    long long result = pow(32, abs(a-b));
    cout << result << endl;

    return 0;
}