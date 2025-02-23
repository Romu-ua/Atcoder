#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'W') {
            s[i] = 'C';
            s[i + 1] = 'A';
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    return (0);
}