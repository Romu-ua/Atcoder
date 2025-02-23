#include <bits/stdc++.h>
using namespace std;

int main() {
    // DPっぽい
    long long n, x;
    string s;
    cin >> n >> x >> s;



    vector<int> dp(s.length(), 0);
    for (int i = 1; i < (int)s.length()-1; i++) {
        if (s[i] == 'R') {
            x *= 2;
        } else if (s[i] == 'L') {
            x = x*2 + 1;
        } else {
            x /= 2;
        }
    }
    cout << x << endl;

    return 0;
}