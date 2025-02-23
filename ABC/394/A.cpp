#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string output;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '2') {
            output += s[i];
        }
    }
    cout << output << endl;
    return (0);
}