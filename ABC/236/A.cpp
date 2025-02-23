#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    a--, b--;
    swap(s[a], s[b]);
    cout << s << endl;
    return 0;
}