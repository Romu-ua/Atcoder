#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    string s;
    cin >> s;

    // sを２進すうの文字列にする
    string d = bitset<61>(x).to_string();
    for (char c : s) {
        if (c == 'U') d.pop_back();
        if (c == 'L') d += '0';
        if (c == 'R') d += '1'; 
    }

    x = stoll(d, nullptr, 2);
    cout << x << endl;
    return 0;
}